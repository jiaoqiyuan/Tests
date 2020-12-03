/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    // 可以使用尾插法解决
    ListNode* oddEvenList(ListNode* head) {
        // if (!head || !head->next || !head->next->next) return head;

        // ListNode *cur = head;
        // ListNode *tail = NULL;
        // int len = 0;
        // while(cur) {
        //     len ++;
        //     tail = cur;
        //     cur = cur->next;
        // }

        // cur = head;
        // for (int i = 1; i <= len; i++) {
        //     if (i == len && len % 2 != 0) {
        //         break;
        //     } else if (i == len && len % 2 != 0) {
        //         tail->next = cur;
        //         cur->next = NULL;
        //         tail = cur;
        //         break;
        //     }
        //     ListNode *tmp = cur->next;
        //     if (i % 2 != 0) {
        //         cur->next = cur->next->next;
        //     } else {
        //         tail->next = cur;
        //         cur->next = NULL;
        //         tail = cur;
        //     }
        //     cur = tmp;
        // }

        // return head;

        if(!head || !head->next) return head;
        // 奇数尾指针
        ListNode *odd_tail = head;
        // 偶数头指针
        ListNode *even_head = head->next;
        // 偶数尾指针
        ListNode *even_tail = even_head;

        while(odd_tail->next && even_tail->next) {
            odd_tail->next = even_tail->next;
            odd_tail = even_tail->next;
            even_tail->next = odd_tail->next;
            even_tail = odd_tail->next;
        }
        odd_tail->next = even_head;
        return head;
    }
};
// @lc code=end

