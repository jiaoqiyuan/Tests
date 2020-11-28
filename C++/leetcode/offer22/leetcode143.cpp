//
// Created by mac on 2020/9/29.
//

#include "iostream"
#include "../ListNode.h"

using namespace std;


class Solution {
public:
    ListNode *reverst_list(ListNode *head) {
        // if (!head || !head->next) return head;

        ListNode *pre = NULL;
        ListNode *cur = head;
        while (cur) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    // 思路：找到中间点，将后半段链表反转，前后两段链表依次合并
    void reorderList(ListNode* head) {
        // 如果链表为空，或者只有一个节点
        if (!head || !head->next) return;

        // 快慢指针找到中间节点
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // 反转后面的链表
        ListNode *head1 = reverst_list(slow->next);
        // if (!head1) cout << "NULL" << endl;
        // while(head1 != NULL) {
        //     cout << head1->val;
        //     cout << endl;
        //     head1 = head1->next;
        // }
        slow->next = NULL;
        ListNode *head2 = head;

        // 合并两个链表
        while (head1 && head2) {
            ListNode *tmp2 = head2->next;
            ListNode *tmp1 = head1->next;
            head2->next = head1;
            head1->next = tmp2;
            head2 = tmp2;
            head1 = tmp1;
        }

    }
};

void test_leetcode143() {
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
    solution.reorderList(node1);
    while(node1) {
        cout << node1->val;
        cout << endl;
        node1 = node1->next;
    }
}

void test_reverse() {
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
    ListNode *node = solution.reverst_list(node1);
    while(node) {
        cout << node->val;
        cout << endl;
        node = node->next;
    }
}

int main() {
    test_leetcode143();
}