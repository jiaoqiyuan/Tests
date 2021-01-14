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
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
    
    ListNode* mergeSort(ListNode* node) {
        if (!node || !node->next) return node;
        //快慢指针
        ListNode* fast = node;
        ListNode* slow = node;
        ListNode* breakN = node;
        while (fast && fast->next) {
            fast = fast->next->next;
            breakN = slow;
            slow = slow->next;
        }
        breakN->next = nullptr;
        ListNode *l1 = mergeSort(node);
        ListNode *l2 = mergeSort(slow);
        return merge(l1, l2);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        //递归到底的情况
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        //分情况递归实现
        if (l1->val <= l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l2->next, l1);
            return l2;
        }
    }
};
// @lc code=end

