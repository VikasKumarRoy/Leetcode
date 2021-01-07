// Problem - 82

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* prev = NULL, *curr = head->next, *start = head, *newHead = NULL;
        int ctr = 0;
        while(curr) {
            if(curr->val == start->val) {
                curr = curr->next;
                ctr++;
            }
            else {
                if(ctr > 0) {
                    if(!prev)
                        newHead = curr;
                    else
                        prev->next = curr;
                    start = curr;
                    curr = curr->next;
                }
                else {
                    if(!newHead)
                        newHead = start;
                    prev = start;
                    start = curr;
                    curr = curr->next;
                }
                ctr = 0;
            }
        }
        if(ctr > 0 && newHead == start)
            return NULL;
        if(ctr > 0 && prev)
            prev->next = NULL;
        return newHead;
    }
};
