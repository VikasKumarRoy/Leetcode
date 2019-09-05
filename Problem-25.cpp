//Problem - 25
// https://leetcode.com/problems/reverse-nodes-in-k-group/

// Time Complexity O(n)

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = NULL, *next = NULL;
    ListNode* curr = head;
    if(!head || !head->next)
        return head;
    int ctr = 0, flag = 0;
    ListNode *test = head;
    while(test){
        test = test->next;
        ctr++;
        if(ctr>=k) {
            flag= 1;
            break;
        }
    }
    if(!flag)
        return head;
    ctr = 0;
    while(curr && ctr<k) {
        ListNode* temp = curr;
        curr = curr->next;
        temp->next = prev;
        prev = temp;
        ctr++;
    }
    if(curr) {
          head->next = reverseKGroup(curr, k);
      }
    return prev;
    }
};
