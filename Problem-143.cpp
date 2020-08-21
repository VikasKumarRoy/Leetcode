// Problem - 143

// https://leetcode.com/problems/reorder-list/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head)
            return;
        stack <ListNode* > s;
        int ctr = 0;
        ListNode* curr = head;
        while(curr) {
            s.push(curr);
            ctr++;
            curr = curr->next;
        }
        ctr /= 2;
        curr = head;
        while(ctr--) {
            ListNode* temp = curr->next;
            auto node = s.top();
            s.pop();
            curr->next = node;
            node->next = temp;
            curr = temp;
        }
        curr->next = NULL;
    }
};
