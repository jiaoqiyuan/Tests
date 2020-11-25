#!/usr/bin/env python3
# coding = utf-8

"""
一些全局变量
"""

import config
import db_config
import db_tools

import tqdm
import json

from config import logger
from Intervaltree import IntervalTree

# 不要直接使用这些变量，应该使用类似 get_* 的函数获取
global __TR_Data
__TR_Data = None

global __TR_Path_Data
__TR_Path_Data = None

global __TR_DiGraph_Data
__TR_DiGraph_Data = None

global __TR_DiGraph_Inner_Data
__TR_DiGraph_Inner_Data = None

global __AS_Info_Data
__AS_Info_Data = None

global __All_Interface_IP
__All_Interface_IP = None

global __IP_Geo_Info_Data
__IP_Geo_Info_Data = None

global __Router_Interface_Alias
__Router_Interface_Alias = None

@config.timethis
def get_tr_data():
    """
    获取 TR 数据，直接返回从数据库查出来的数据，一个二维元组
    """
    global __TR_Data
    if __TR_Data is not None:
        logger.info("Use cached TR data")
        return __TR_Data

    logger.info("Query TR data from database")

    sql_get_tr = """
        SELECT ip_num, vpid, step, i_ip_num, delay, isalive
        FROM `{}`
        ORDER BY id
        """.format(db_config.Table_TraceRoute)
    
    conn, cur = db_tools.get_new_conn_and_cursor()
    cur.execute(sql_get_tr)
    __TR_Data = cur.fetchall()
    db_tools.close_conn_and_cursor(conn, cur)
    return __TR_Data

@config.timethis
def get_tr_path_data():
    """
    将 TR 数据整合成路径数据， 返回下面的数据类型，其中 PATH = tuple：
    { PATH( i_ip_num, ..., dest_ip, isalive), ... }
    注意 PATH 列表中的最后一个元素是 isalive 的标记，0 或 1
    返回一个包含 path 的集合 set
    """
    global __TR_Path_Data
    if __TR_Path_Data is not None:
        logger.info("Use cached TR path data")
        return __TR_Path_Data

    tr_path_data = set()
    tr_data = get_tr_data()
    path = []
    for (ip_num, _vpid, _step, i_ip_num, _delay, isalive) in tqdm.tqdm(tr_data, "Generate TR path data"):
        path.append(i_ip_num)
        if ip_num == i_ip_num:
            path.append(isalive)
            tr_path_data.add(tuple(path))
            # 对 path 赋值新 list 对象
            path = []
    __TR_Path_Data = tr_path_data
    return __TR_Path_Data

@config.timethis
def get_tr_digraph_data():
    """
    将 TR 路径数据整合成有向图数据，整合过程中排除掉路径中的目的 IP，只要路由器接口 IP
    """
    global __TR_DiGraph_Data
    if __TR_DiGraph_Data is not None:
        logger.info("Use cached TR directed graph data")
        return __TR_DiGraph_Data

    tr_path_data = get_tr_path_data()
    __TR_DiGraph_Data = __get_tr_digraph_data_by_tr_path_data(tr_path_data)
    return __TR_DiGraph_Data

@config.timethis
def get_tr_digraph_inner_data():
    """
    将整理过的域内 TR 路径数据整合成有向图数据，整合过程中排除掉路径中的目的 IP，只要路由器接口 IP
    """
    global __TR_DiGraph_Inner_Data
    if __TR_DiGraph_Inner_Data is not None:
        logger.info("Use cached TR directed graph inner data")
        return __TR_DiGraph_Inner_Data

    tr_path_inner_data = get_tr_path_inner_data()
    __TR_DiGraph_Inner_Data = __get_tr_digraph_data_by_tr_path_data(tr_path_inner_data)
    return __TR_DiGraph_Inner_Data


@config.timethis
def get_alias_data():
    """
    返回一个字典，接口 ip 为键，对应的 alias_id 为值
    """
    if db_config.Table_Router_Interface_Alias is None:
        logger.warn("No alias data found")
        return None

    global __Router_Interface_Alias
    if __Router_Interface_Alias is not None:
        logger.info("Use cached router interface alias data")
        return __Router_Interface_Alias

    logger.info("Query router interface alias data from database")

    sql_get_alias = """
        SELECT num_ip, alias_id
        FROM `{}`
        """.format(db_config.Table_Router_Interface_Alias)

    conn, cur = db_tools.get_new_conn_and_cursor()
    cur.execute(sql_get_alias)
    __Router_Interface_Alias = {i_ip_num : alias_id for (i_ip_num, alias_id) in cur.fetchall()}
    db_tools.close_conn_and_cursor(conn, cur)
    return __Router_Interface_Alias

@config.timethis
def get_as_info_data():
    """
    获取 IP 块到 AS 信息（AS 号，AS 名字）的对应关系
    返回一个 IntervalTree 对象
    """
    global __AS_Info_Data
    if __AS_Info_Data is not None:
        logger.info("Use cached AS Info data")
        return __AS_Info_Data

    logger.info("Query IP to AS info data from database")

    sql_get_as_info = """
        SELECT minip, maxip, asnumber, asname
        FROM `{}`
        """.format(db_config.Table_IP_AsInfo)
    
    conn, cur = db_tools.get_new_conn_and_cursor()
    cur.execute(sql_get_as_info)
    feed = []
    # 如果数据库里 asname 是 NULL 那么 python 里得到值为 None
    for (minip_num, maxip_num, asnumber, asname) in cur.fetchall():
        # asnumber 可能包含多个 as，只要第一个
        as_info = (int(asnumber.split(",")[0]), asname)
        data = (minip_num, maxip_num, as_info)
        feed.append(data)
    logger.info("Building ip to as info interval tree")
    __AS_Info_Data = IntervalTree(feed, 0, 4294967295)
    db_tools.close_conn_and_cursor(conn, cur)
    return __AS_Info_Data

@config.timethis
def get_ip_geo_info_data():
    """
    获取街道级定位数据，IP 块到位置信息的对应关系，位置信息使用元组（必须可 hash），依次为：
    (num_minip, num_maxip, country, province, city)
    返回一个 IntervalTree 对象
    """
    global __IP_Geo_Info_Data
    if __IP_Geo_Info_Data is not None:
        logger.info("Use cached ip geo info data")
        return __IP_Geo_Info_Data

    logger.info("Query ip geo info data from database")

    sql_get_data = """
        SELECT num_minip, num_maxip, country, province, city
        FROM `{}`
        """.format(db_config.Table_IP_GeoInfo)

    conn, cur = db_tools.get_new_conn_and_cursor()
    cur.execute(sql_get_data)
    feed = []
    # multiarea_bd 类型：[{"w":"26.080311","j":"119.302605","r":"296.4245","p":"福建省","c":"","d":""}]
    for (num_minip, num_maxip, country, province, city) in cur.fetchall():
        geo_info = (num_minip, num_maxip, country, province, city)
        data = (num_minip, num_maxip, geo_info)
        feed.append(data)
    logger.info("Building ip geo info interval tree")
    __IP_Geo_Info_Data = IntervalTree(feed, 0, 4294967295)
    db_tools.close_conn_and_cursor(conn, cur)
    return __IP_Geo_Info_Data
