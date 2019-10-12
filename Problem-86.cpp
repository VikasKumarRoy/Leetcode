//Problem - 86
// https://leetcode.com/problems/partition-list/

// O(n) time complexity and O(1) space solution

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head)   return head;
        ListNode *smaller = NULL, *greater = NULL, *smallerEnd = NULL, *greaterEnd = NULL;
        while(head) {
            if(head->val >= x) {
                if(!greater) {
                    greater = greaterEnd = head;
                }
                else {
                    greaterEnd->next = head;
                    greaterEnd = head;
                }
            }
            else {
                if(!smaller) {
                    smaller = smallerEnd = head;
                }
                else {
                    smallerEnd->next = head;
                    smallerEnd = head;
                }
            }
            head = head->next;
        }
        if (greater)
            greaterEnd->next = NULL;
        if(!smaller)
            return greater;
        smallerEnd->next = greater;
        return smaller;
    }
};