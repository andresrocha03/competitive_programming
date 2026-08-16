//Problem:Detect a cycle in a linked list
//Solution: traverse the list changing the value of nodes to know if it was already visited or not. If we reach nullptr, no cycle. If we reach a visited node, then there is a cycle;

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
        bool hasCycle(ListNode* head) {
            while (head) {
                if (head->val == -1007) return true;
                head->val = -1007;
                head = head->next;
            }
            return false;
        }
};
