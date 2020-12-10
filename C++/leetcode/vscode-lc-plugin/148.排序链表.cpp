/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // TODO超时，使用归并排序的思路
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode *dummy = new ListNode(-1);
        while(head) {
            ListNode *p = dummy;
            while(p->next && p->next->val < head->val) p = p->next;
            ListNode *q = head;
            head = head->next;
            q->next = p->next;
            p->next = q;
        }
        return dummy->next;
    }
};
// @lc code=end

