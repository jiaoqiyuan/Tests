/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (59.65%)
 * Likes:    465
 * Dislikes: 0
 * Total Accepted:    72.3K
 * Total Submissions: 121.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 示例 1:
 * 
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 * 
 * 示例 2:
 * 
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
 * 
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

    ListNode *reverst_list(ListNode *head) {
        if (!head || !head->next) return head;

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
// @lc code=end

