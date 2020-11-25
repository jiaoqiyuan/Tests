#!/usr/bin/env python3
# coding = utf-8


"""
数据库相关配置
警告！建表语句会删除已存在的旧表！
"""

DB_CONFIG = {
}

# 基础数据表
# 注意：如果提供了 alias 表，程序会修改 alias 表结构并插入新数据，注意备份原表
Table_TraceRoute = "202005_CN_tr_ALL" # 使用下面的表达式匹配搜索表，将匹配到的表的数据放到这个表里
Tables_TraceRoute_Match_Reg = r"202004\_ldk\_tr\_vp\_%\_%" # 注意，要确保这个表达式不会匹配到其他无关表
Table_IP_AsInfo = "lss_ip_as_20200601_done" # ip 与 as 关系表
Table_Router_Interface_Alias = None # 注意！如果没有 alias 数据，切记这项的值要改为 None
# Table_IP_GeoInfo = "aiwen_geoip_street_single_sorted" # 全球街道级定位表
Table_IP_GeoInfo = "aiwen_geoip_202010" # 全球街道级定位表
