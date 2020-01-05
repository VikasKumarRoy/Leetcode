// Problem - 141

// https://leetcode.com/problems/linked-list-cycle/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(slow != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return 1;
        }
        return 0;
    }
};