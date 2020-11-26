/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    // 利用快慢指针，快指针先走 n 步，然会快慢指针一起便利
    // 快指针为空时慢指针指向的节点就是要删除的节点
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0) return head;
        if (head == NULL || head->next == NULL) return NULL;

        ListNode *fast = head;
        ListNode *slow = head;
        
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        if (fast == NULL) return head->next;

        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
// @lc code=end

