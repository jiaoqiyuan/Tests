/**
 * 删除链表中间节点
 * [4,1,5,9] 5 => [4,1,9]
 * */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include "../ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *pre = new ListNode(0);
        ListNode *current = head;
        pre->next = current;
        ListNode *result = pre;
        while (current) {
            if (current->val == val) {
                pre->next = current->next;
                break;
            }
            pre = current;
            current = current->next;
        }
        return result->next;
    }
};

void test_offer18() {
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
    ListNode *node = solution.deleteNode(node1, 3);
    while(node) {
        cout << node->val;
        cout << endl;
        node = node->next;
    }
}