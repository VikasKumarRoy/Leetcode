// Problem - 876

// https://leetcode.com/problems/middle-of-the-linked-list/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

