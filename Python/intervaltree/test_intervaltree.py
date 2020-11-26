#!/usr/bin/env python3
# coding=utf-8

import global_data
import db_tools
import tqdm
from Intervaltree import IntervalTree

from config import logger

def get_geo_info_for(i_ip_num, geo_info_data, min_max_ip_map):
    # 方式1：遍历，耗时太久
    # logger.info("begine geo geo info for {}".format(i_ip_num))
    # for geo_info in geo_info_data:
    #     if i_ip_num >= geo_info[0] and i_ip_num <= geo_info[1]:
    #         return geo_info

    # 二分法查找
    count = 0
    low = list(min_max_ip_map.keys())[0]
    high = list(min_max_ip_map.keys())[-1]
    while(low <= high):
        mid = int((low + high) / 2)
        value = min_max_ip_map[mid]
        # print("value = {}".format(value))
        if i_ip_num >= value[0] and i_ip_num <= value[1]:
            logger.info("count = {}".format(count))
            return geo_info_data[value]
        elif i_ip_num > value[1]:
            low = mid + 1
        else:
            high = mid - 1
        count += 1
    return "None"

def test_get_geo_info():
    geo_info_data = global_data.get_ip_geo_info_data()

    # 创建一个映射关系，根据定位库中IP区间的顺序为每个ip区间映射一个值
    # 878690:(415752656, 415752663)
    min_max_ip_map = {}
    for index, geo_info in tqdm.tqdm(enumerate(geo_info_data), "generate maping for geo_info_data...."):
        min_max_ip_map[index] = geo_info

    logger.info("get geo info done. len = {}".format(len(geo_info_data)))
    tr_data = global_data.get_tr_data()
    logger.info("get tr data done. len = {}".format(len(tr_data)))
    for data in tqdm.tqdm(tr_data, "geting tr data geo info ..."):
        router_ip = data[3]
        geo_info = get_geo_info_for(router_ip, geo_info_data, min_max_ip_map)
        print("{}:{}".format(router_ip, geo_info))

def test_intervaltree():
    features = [(20,400,'id01'),(1020,2400,'id02'),(29949, 35891,'id03'),(900000,900000,'id04'),(999000,999000,'id05')]
    intervaltree = IntervalTree(features, 0, 100000)
    result = intervaltree.find_range([20000, 40000])
    print(result)

if __name__ == "__main__":
    logger.info("Hello!")
    test_intervaltree()

