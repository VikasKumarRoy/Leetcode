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

// OR O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int getLength(ListNode* l) {
        int ctr = 0;
        while(l) {
            ctr++;
            l = l->next;
        }
        return ctr;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* prev = NULL;
        int n1 = getLength(l1), n2 = getLength(l2);
        if(n2 > n1)
            swap(l1, l2);
        int ctr = abs(n1 - n2);
        while(ctr--) {
            ListNode* node = new ListNode(l1->val);
            l1 = l1->next;
            node->next = prev;
            prev = node;
        }
        while(l1 && l2) {
            ListNode* node = new ListNode(l1->val + l2->val);
            l1 = l1->next;
            l2 = l2->next;
            node->next = prev;
            prev = node;
        }
        int carry = 0;
        // Normalization and reverse the ans list
        ListNode* head = prev;
        prev = NULL;
        while(head) {
            head->val += carry;
            carry = head->val/10;
            head->val %= 10;
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        if(carry) {
            ListNode* node = new ListNode(carry);
            node->next = prev;
            prev = node;
        }
        return prev;
    }
};
