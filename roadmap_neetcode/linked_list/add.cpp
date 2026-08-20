// Problem: Given two numbers written in linked list format, from least significant digit to most, add them up and return the result in the same format.
// Sol: CHeck which list is longer and them traverse thhe two lists in parallel until the end of the shorter one. Sum during traversal (and in the end if necessary).

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

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        //check longest list
        ListNode* l11 = l1;
        ListNode* l22 = l2;

        while (l11 && l22) {
            l11 = l11->next;
            l22 = l22->next;
        }
        
        ListNode* small;
        ListNode* longi;
        if (!l22) {
            longi = l1;
            small = l2;
        }
        else {
            small = l1;
            longi = l2;
        }

        //compute sum
        int carry = 0;
        ListNode* res = longi;
        while (small || longi) {
            int x1 = longi->val;
            int x2 = small ? small->val : 0;
            
            longi->val = (x1+x2+carry)%10;
            carry = (x1+x2+carry)/10;

            if (!longi->next) break;
            longi = longi->next;
            small = small ? small->next : nullptr;
        }
        
        if (carry) {
            ListNode* aux = new ListNode(carry);
            longi->next = aux;
        }
        
        return res;
    }
};
