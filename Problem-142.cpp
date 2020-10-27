// Problem - 142

// https://leetcode.com/problems/linked-list-cycle-ii/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow, *fast;
        slow = fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                break;
            }
        }
        if(fast && fast->next) {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
        return NULL;
    }
};
