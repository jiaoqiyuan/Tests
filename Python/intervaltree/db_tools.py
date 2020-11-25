#!/usr/bin/env python3
# coding=utf-8


import db_config

import os
import subprocess
import tqdm

from config import logger

import MySQLdb # requires pip3 install mysqlclient
from MySQLdb.cursors import Cursor

def get_new_conn_and_cursor():
    conn = MySQLdb.connect(**db_config.DB_CONFIG)
    conn.ping()
    return conn, conn.cursor()

def close_conn_and_cursor(conn, cur):
    cur.close()
    conn.commit()
    conn.close()

def save_data_to_local_file(file_name, fields_ter, data):
    with open(file_name, "w") as f:
        for row in tqdm.tqdm(data, "Save data to local file"):
            row_in_str = [str(elem) for elem in row]
            line = fields_ter.join(row_in_str) + os.linesep
            f.write(line)

def load_local_data_to_table(load_sql):
    # NOTE(ri): 直接使用 execute 的方式执行 load sql 将会报如下错误，因此改为调用系统命令的方式进行 load 数据
    # MySQLdb._exceptions.OperationalError: (2027, 'Malformed packet')
    # 测试机器：192.168.1.26，测试服务器信息：5.5.35-1ubuntu1，3306 端口
    logger.info("Load data to db")
    host = db_config.DB_CONFIG["host"]
    port = str(db_config.DB_CONFIG["port"])
    db = db_config.DB_CONFIG["db"]
    user = db_config.DB_CONFIG["user"]
    passwd = db_config.DB_CONFIG["passwd"]
    cmd = ["mysql", "-h", host, "-P", port, "-u", user, "--password={}".format(passwd), "-e", load_sql, db]
    ret = subprocess.run(cmd)
    if ret.returncode != 0:
        logger.error("Load data to db failed!")
        return
    logger.info("Load data to db done")
