/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *dummy = new ListNode(-1);
        while (head) {
            ListNode *p = dummy;
            while(p->next && p->next->val < head->val) {
                p = p->next;
            }
            ListNode *q = head;
            head = head->next;

            q->next = p->next;
            p->next = q;
        }
        
        return dummy->next;
    }
};
// @lc code=end

