//
// Created by mac on 2020/9/7.
//

#include <iostream>
#include "GoodGay.h"

Building::Building() {
    m_living_room = "living room";
    m_bedroom = "bed room";
}

GoodGay::GoodGay() {
    building = new Building;
}

void GoodGay::visit() {
    cout << "visit " << building->m_living_room << endl;
    cout << "visit " << building->m_bedroom << endl;

}

void test01() {
    GoodGay goodGay;
    goodGay.visit();
}

int main() {
    test01();
    return 0;
}