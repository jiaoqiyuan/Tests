//
// Created by mac on 2020/9/7.
//

#ifndef HELLOCPP_GOODGAY_H
#define HELLOCPP_GOODGAY_H

#include <string>

using namespace std ;

class Building;

class GoodGay {
public:
    GoodGay();

    void visit();   // 让 visit 访问 Building 中的私有成员
    Building *building;
};

class Building {
    friend void GoodGay::visit();
public:
    Building();

    string m_living_room;
private:
    string m_bedroom;
};

#endif //HELLOCPP_GOODGAY_H
