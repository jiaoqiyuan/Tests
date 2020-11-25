#!/usr/bin/env python3
# coding = utf-8

import json

"""
{
  "duplicated" : 339,
  "size" : 7660,
  "node" : [ {
    "ip" : "0000:0000:0000:0000:0000:ffff:1f11:4650",
    "port" : 8333,
    "duplicated" : 0,
    "count" : 1,
    "netaddr" : [ {
      "time" : 1603827221,
      "services" : 1085,
      "ip" : "0000:0000:0000:0000:0000:ffff:1f11:4650",
      "port" : 8333
    } ],
    "tag" : [ {
      "from_ip" : "0000:0000:0000:0000:0000:ffff:2252:aaf6",
      "from_time" : 1603852271114
    } ]
  }, ...]
}
"""

with open("20201028103205-node copy.json", 'r') as f:
    nodes = json.loads(f.read())
    node_elems = nodes['node']
    for node_elem in node_elems:
        ip = node_elem['ip']
        port = node_elem['port']
        tag = node_elem['tag']
        from_ip = None
        from_time = None
        for tag_elem in tag:
            from_ip = tag_elem['from_ip']
            from_time = tag_elem['from_time']
        
        print("{},{},{},{}".format(ip, port, from_ip, from_time))
