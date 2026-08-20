//Problem: Given a linked list, remove the nth element from its end and return the head
//Sol: Find out index relative to the start. Inset a dummy at position zero and go until the left neighbor of the chosen node. Eliminate it by changing the next pointer of the left neighbor to point to the right neighbor of the chosen node. Then, it is easy to remove it.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* dummy = new ListNode(0,head);

        //count number of nodes
        ListNode* node = head;
        int i=0;
        while (node) {
            i++;
            node = node->next;
        }

        //node position from the start
        int idx = i-n+1;
    
        //go until the left neighbor of the chosen node
        int j=0;
        ListNode* left_nei=dummy;
        while (j<idx-1) {
            left_nei = left_nei->next;
            j++;
        }

        //eliminate
        ListNode* aux = left_nei->next->next;
        left_nei->next = aux;

        return dummy->next;        
    }
};
