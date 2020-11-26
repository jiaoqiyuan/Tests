/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    // 交换节点可以理解为换值或者换节点，都可以实现交换的目的
    // 这里以换值来解决，比较方便
    ListNode* swapPairs(ListNode* head) {
        // 如果头节点为空或者只有一个节点，直接返回头节点
        if (head == NULL || head->next == NULL) return head;

        ListNode *cur = head;
        while(cur != NULL && cur->next != NULL) {
            ListNode *next = cur->next;
            int tmp = cur->val;
            cur->val = next->val;
            next->val = tmp;
            cur = cur->next->next;
        }
        return head;
    }
};
// @lc code=end

