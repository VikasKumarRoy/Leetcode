// Problem - 237

// https://leetcode.com/problems/delete-node-in-a-linked-list/

// O(1) time complexity and O(1) space solution

class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *node->next;
    }
};
