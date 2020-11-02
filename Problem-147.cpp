// Problem - 147

// https://leetcode.com/problems/insertion-sort-list/

// O(n^2) time complexity and O(1) space complexity solution

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head)
            return head;
        ListNode *dummy = new ListNode(0);
        ListNode* curr = head, *prev = dummy;
        while(curr) {
            ListNode* next = curr->next;
            prev = dummy;
            while(prev->next != NULL && prev->next->val < curr->val) {
                prev = prev->next;
            }
            curr->next = prev->next;
            prev->next = curr;
            curr = next;
        }
        return dummy->next;
    }
};
