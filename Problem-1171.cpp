//Problem - 1171
// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

// Time Complexity O(n) and O(n) space

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head)
            return NULL;
        ListNode dummy(0) ;
        dummy.next = head;
        head = &dummy;
        unordered_map <int, ListNode*> um;
        int sum = 0;
        ListNode* curr = head;
        while(curr) {
            sum += curr->val;
            if(um.find(sum) != um.end()) {
                int tempSum = sum;
                ListNode* temp = um[sum]->next;
                while(temp != curr) {
                    tempSum += temp->val;
                    um.erase(tempSum);
                    temp = temp->next;
                }
                um[sum]->next = curr->next;
            }
            else {
                um[sum] = curr;
            }
            curr = curr->next;
        }
        return head->next;;
    }
};

