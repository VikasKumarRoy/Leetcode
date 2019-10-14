//Problem - 206
// https://leetcode.com/problems/reverse-linked-list/

// O(n) time complexity and O(1) space complexity

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
      ListNode* curr = head;
      if(!head || !head->next)
        return head;
      while(curr) {
          ListNode* temp = curr;
          curr = curr->next;
          temp->next = prev;
          prev = temp;
      }
      return prev;
    }
};