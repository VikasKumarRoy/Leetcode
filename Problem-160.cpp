// Problem - 160

// https://leetcode.com/problems/intersection-of-two-linked-lists/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA = headA, *tempB = headB;
        int ctrA = 0, ctrB = 0;
        while(tempA) {
            ctrA++;
            tempA = tempA->next;
        }
        while(tempB) {
            ctrB++;
            tempB = tempB->next;
        }
        int diff = abs(ctrA - ctrB);
        tempA = headA, tempB = headB;
        if(ctrB > ctrA)
            swap(tempA, tempB);
        while(diff--) {
            tempA = tempA->next;
        }
        while(tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
};
