//Problem - 61
// https://leetcode.com/problems/rotate-list/

// O(n) time complexity and O(1) space complexity sol

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
            return head;
        int n = 1;
        ListNode* curr = head, *prev = NULL;
        while(curr->next) {
            n++;
            curr = curr->next;
        }
        curr->next = head;
        prev = curr;
        int ctr = n - k%n + 1;
        while(ctr--) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        return curr;
    }
};