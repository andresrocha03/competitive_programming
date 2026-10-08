//Problem: You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
//Solution: Traverse both linked lists, adding corresponding digits and keeping track of carry. Create a new linked list to store the result. Continue until both lists are fully traversed and there is no carry left.


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* ans = head;

        int carry = 0;
        while (l1 || l2 || carry) {
            int x1 = l1 ? l1->val:0;
            int x2 = l2 ? l2->val:0;

            int x3 = (x1+x2 + carry);
            carry = x3/10;
            x3 %= 10;

            ans->next = new ListNode(x3);
            ans = ans->next;
            l1 = l1 ? l1->next: nullptr;
            l2 = l2 ? l2->next: nullptr;
        }

        return head->next;
    }
};