//
// Created by mac on 2020/9/29.
//

#ifndef HELLOCPP_LISTNODE_H
#define HELLOCPP_LISTNODE_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void test_offer18();
void test_offer22();

#endif //HELLOCPP_LISTNODE_H
