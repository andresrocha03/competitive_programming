//Problem: Given to single linkd lists, we want to merge them into a new sorted single linked list
//Solution: Use one pointer in each list. We always take the smaller element and advance in the list who had it, until we reach the end of both lists (nullptr);

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

            ListNode pre_head(0);            
            ListNode* tail = &pre_head;

            while (list1 && list2) {
                if (list1->val <= list2->val) {
                    tail->next = list1;     
                    list1 = list1->next;
                }
                else {
                    tail->next = list2;
                    list2 = list2->next;
                }
                tail = tail->next;
            }

            if (!list1) {
                tail->next = list2;
            }
            if (!list2) {
                tail->next = list1;
            }

            return pre_head.next;
        }
};