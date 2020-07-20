// Problem - 203

// https://leetcode.com/problems/remove-linked-list-elements/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev, *newHead, *curr = head;
        prev = newHead = NULL;
        bool flag = true;
        while(curr) {
            if(curr->val == val) {
                if(prev)
                    prev->next = curr->next;
            }
            else {
                prev = curr;
                if(flag) {
                    newHead = curr;
                    flag = false;
                }
            }
            curr = curr->next;
        }
        return newHead;
    }
};
