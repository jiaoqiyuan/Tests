#include <iostream>
#include "../ListNode.h"

using namespace std;

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
    ListNode *root;
    bool flag = true;

    void dfs(ListNode* head) {
        if (!head) return;
        dfs(head->next);
        if (head->val != root->val) flag = false;
        root = root->next;
    } 

    bool isPalindrome(ListNode* head) {
        root = head;
        dfs(head);
        return flag;
    }
};

void testIsPalindrome() {
    auto *node1 = new ListNode(1);
    auto *node2 = new ListNode(0);
    auto *node3 = new ListNode(2);
    node1->next = node2;
    node2->next = node3;
    Solution solution;
    bool result = solution.isPalindrome(node1);
    cout << result << endl;
}

int main() {
    testIsPalindrome();
}