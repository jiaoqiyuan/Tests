#!/usr/bin/env python3
# coding = utf-8
# author = listenerri
# maintainer = listenerri

"""
程序相关配置
数据库相关配置请看 db_config.py
"""

import logging
import time

from functools import wraps

logger = logging.getLogger()
handler = logging.StreamHandler()
formatter = logging.Formatter('%(asctime)s[%(levelname)s] %(message)s')
handler.setFormatter(formatter)
logger.addHandler(handler)
logger.setLevel(logging.INFO)

router_cache_path = "cache/router/"
tr_cache_path = "cache/tr/"

def timethis(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        logger.info("%s called" % (func.__name__))
        start = time.time()
        result = func(*args, **kwargs)
        end = time.time()
        logger.info("%s %f" % (func.__name__, end - start))
        return result
    return wrapper
