// Problem: Given a single linked list. Reorder it like 0, n-1, 1, n-2, 2, ..., where the numbers are the indexes in the original array
// Solution: Divide the list into two halves to be merged. Invert the right half, then merge taking one element from right half and one from left.

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
    ListNode *invert(int index, ListNode *head)
    {

        // reach the head of the right half
        ListNode *newhead = head;
        int i = 0;
        while (i < index)
        {
            i++;
            newhead = newhead->next;
        }

        // invert the order
        ListNode *curr = newhead;
        newhead = nullptr;
        while (curr)
        {
            ListNode *nexit = curr->next; // save element to be processed in the next iteration
            curr->next = newhead;         // invert link
            newhead = curr;               // update newhead with the element that was processed
            curr = nexit;                 // update current
        }
        return newhead;
    }

    void reorderList(ListNode *head)
    {
        ListNode *node = head->next;
        int n = 0;

        // counting the number of nodes after zero
        while (node)
        {
            n++;
            node = node->next;
        }

        // divide into two halves
        int div_index = n / 2;

        // invert the order of right half
        ListNode *rhead = invert(div_index, head->next);

        // merge
        ListNode *lhead = head;
        while (rhead)
        {
            ListNode *auxl = lhead->next;
            lhead->next = rhead;
            ListNode *auxr = rhead->next;
            rhead->next = auxl;
            lhead = auxl;
            rhead = auxr;
        }
        lhead->next = rhead;
    }
};
