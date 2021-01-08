// Problem - 83

// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head, ListNode* prev = NULL) {
        if(!head)
            return head;
        if(prev && head->val == prev->val) {
            return deleteDuplicates(head->next, prev);
        }
        ListNode *temp = head;
        temp->next = deleteDuplicates(head->next, head);
        return temp;
    }
};
