// Problem - 328

// https://leetcode.com/problems/odd-even-linked-list/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return head;
        ListNode* evenStart = head->next;
        ListNode* odd = head, *even = evenStart;
        while(even && odd) {
            ListNode* temp = even->next;
            if(temp) {
                odd->next = temp;
                odd = temp;
                even->next = temp->next;
                even = temp->next;
            }
            else {
                even->next = NULL;
                break;
            }
        }
        odd->next = evenStart;
        return head;
    }
};
