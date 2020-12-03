#!/usr/bin/env/python3
# coding = utf-8

count = 0

def test_count():
    global count
    count += 1
    if count % 40 == 0:
        print("[{}] 40 times".format(count))
        count = 0

if __name__ == '__main__':
    for i in range(1, 1000):
        test_count()