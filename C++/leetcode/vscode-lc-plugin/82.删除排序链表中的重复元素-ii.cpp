/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    // 记录前一个不是重复节点那个节点，将重复的节点从链表中删除
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *p = new ListNode(0);
        p->next = head;
        head = p;
        ListNode *left, *right;

        while (p->next) {
            left = p->next;
            right = left;
            while(right->next && right->next->val == left->val) {
                right = right->next;
            }
            if (left == right) p = p->next;
            else p->next = right->next;
        }
        return head->next;
    }
};
// @lc code=end

