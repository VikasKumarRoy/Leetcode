// Problem - 2

// https://leetcode.com/problems/add-two-numbers/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head1 = l1, *head2 = l2;
        ListNode* newHead = new ListNode(0);
        ListNode* curr = newHead;
        while(head1 && head2) {
            int sum = carry + head1->val + head2->val;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* temp = new ListNode(sum);
            curr->next = temp;
            head1 = head1->next;
            head2 = head2->next;
            curr = curr->next;
        }
        while(head1) {
            int sum = carry + head1->val;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* temp = new ListNode(sum);
            curr->next = temp;
            head1 = head1->next;
            curr = curr->next;
        }
        while(head2) {
            int sum = carry + head2->val;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* temp = new ListNode(sum);
            curr->next = temp;
            head2 = head2->next;
            curr = curr->next;
        }
        if(carry) {
           ListNode *temp = new ListNode(carry);
           curr->next = temp;
           curr = curr->next;
        }
        curr->next = NULL;
        return newHead->next;
    }
};
