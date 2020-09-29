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

#endif //HELLOCPP_LISTNODE_H
