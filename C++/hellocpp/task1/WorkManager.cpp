//
// Created by Administrator on 2020/9/15.
//

#include "WorkManager.h"

WorkManager::WorkManager() {

}

WorkManager::~WorkManager() {

}

void WorkManager::show_menu() {
    cout << "*************************************" << endl;
    cout << "********欢迎使用职工管理系统***********" << endl;
    cout << "*********0: 退出管理系统**************" << endl;
    cout << "*********1: 增加职工信息**************" << endl;
    cout << "*********2: 显示职工信息**************" << endl;
    cout << "*********3: 删除职工信息**************" << endl;
    cout << "*********4: 修改职工信息**************" << endl;
    cout << "*********5: 查找职工信息**************" << endl;
    cout << "*********6: 排序*********************" << endl;
    cout << "*********7: 清除所有信息**************" << endl;
    cout << "************************************" << endl;
    cout << endl;
}