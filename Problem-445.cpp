// Problem - 445

// https://leetcode.com/problems/add-two-numbers-ii/

// O(n) time complexity and O(n) space complexity solution using stack

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack <ListNode*> s1, s2;
        while(l1) {
            s1.push(l1);
            l1 = l1->next;
        }
        while(l2) {
            s2.push(l2);
            l2 = l2->next;
        }
        ListNode* prev = NULL;
        int val1, val2, carry = 0;
        while(!s1.empty() || !s2.empty() || carry) {
            val1 = val2 = 0;
            if(!s1.empty()) {
                val1 = s1.top()->val;
                s1.pop();
            }
            if(!s2.empty()) {
                val2 = s2.top()->val;
                s2.pop();
            }
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode* node = new ListNode(sum);
            node->next = prev;
            prev = node;
        }
        return prev;
    }
};
