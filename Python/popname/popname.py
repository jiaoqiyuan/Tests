#!/usr/bin/env python3
# coding = utf-8

a = ['a', 'b', 'c', 'a', 'b', 'd', 'a', 'c', 'a', 'c']

"""
为每个元素编号，从1开始，依次增加
"""
pop_set = set()
for name in a:
    raw_name = name
    pop_name = "{}-1".format(raw_name)
    id = 2
    while pop_name in pop_set:
        pop_name = "{}-{}".format(raw_name, id)
        id += 1
    pop_set.add(pop_name)

print(pop_set)
