//Problem: Given a single linked list, revert it
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
//Sol: Build reverse list as we traverse the original one. The *next attribute of a node x start pointing to x, until we reach the null pointer.

class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            
            ListNode* newhead = nullptr;
            ListNode* curr = head;

            while (curr != nullptr) {
                ListNode* nexit = curr->next;
                curr->next = newhead;
                newhead = curr;
                curr = nexit;
            }

            return newhead;
        }
};