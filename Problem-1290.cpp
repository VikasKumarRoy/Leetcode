//Problem - 1290

// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while(head) {
            ans = ans << 1; 
            ans = ans | head->val;
            head = head->next;
        }
        return ans;
    }
};