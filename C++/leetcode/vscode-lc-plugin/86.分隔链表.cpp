/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;

        ListNode *head_right = new ListNode(0);
        ListNode *right_cur = head_right;
        ListNode *cur = head;
        ListNode *pre = NULL;
        while (cur) {
            if (cur->val >= x) {
                right_cur->next = cur;
                right_cur = right_cur->next;
                if (!pre) head = head->next;
                else pre->next = cur->next;
            } else {
                pre = cur;
            }
            cur = cur->next;
        }
        right_cur->next = NULL;
        if (!pre) return head_right->next;
        else pre->next = head_right->next;

        return head;
    }
};
// @lc code=end

