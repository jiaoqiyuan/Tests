//
// Created by mac on 2020/9/28.
//
#include "iostream"
#include "leetcode1290.h"
#include "../ListNode.h"

using namespace std;

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int len = 0;
        int sum = 0;
        ListNode *current = head;
        while(current) {
            current = current->next;
            len++;
        }
        current = head;
        int index = 0;
        while(current) {
            index++;
            sum += current->val == 1 ? (1 << (len - index)) : 0;
            current = current->next;
        }
        return sum;
    }
};

void test1290() {
    auto *node1 = new ListNode(1);
    auto *node2 = new ListNode(0);
    auto *node3 = new ListNode(1);
    node1->next = node2;
    node2->next = node3;
    Solution solution;
    int ret = solution.getDecimalValue(node1);
    cout << ret;
}

