//
// Created by mac on 2020/9/29.
//

#include "offer22.h"
#include "iostream"
#include "../ListNode.h"

using namespace std;


class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *current = head;
        int len = 0;
        while(current) {
            len++;
            current = current->next;
        }
        current = head;
        int index = 0;
        while(index != (len - k)) {
            len--;
            current = current->next;
        }
        return current;
    }
};

void test_offer22() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    Solution solution;
    ListNode *node = solution.getKthFromEnd(node1, 2);
    while(node) {
        cout << node->val;
        cout << endl;
        node = node->next;
    }
}