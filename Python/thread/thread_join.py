import threading
import time

"""
测试一下 python 多线程中 join 的功能：
测试结果显示，线程 A 加入 join 后，主线程会等待线程 A 执行完毕后再推出
    如果不加 join，主线程不等线程 A 执行完就退出，也就是说，
    join 的作用就是线程同步
"""

def run():

    time.sleep(2)
    print('当前线程的名字是： ', threading.current_thread().name)
    time.sleep(2)


if __name__ == '__main__':

    start_time = time.time()

    print('这是主线程：', threading.current_thread().name)
    thread_list = []
    for i in range(5):
        t = threading.Thread(target=run)
        thread_list.append(t)

    for t in thread_list:
        t.setDaemon(True)
        t.start()

    for t in thread_list:
        print("join")
        #t.join()

    print('主线程结束了！' , threading.current_thread().name)
    print('一共用时：', time.time()-start_time)
