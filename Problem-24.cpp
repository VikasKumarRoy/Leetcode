// Problem - 24

// https://leetcode.com/problems/swap-nodes-in-pairs/

// O(n) time complexity and O(n) space complexity solution 

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return nullptr;
        if(!head->next)
            return head;
        ListNode* temp = head->next;
        head->next = swapPairs(temp->next);
        temp->next = head;
        return temp;
    }
};
