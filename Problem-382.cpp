//Problem - 382

// https://leetcode.com/problems/linked-list-random-node/

// O(n)  time complexity for dfs and O(n) space complexity sol

class Solution {
public:

    ListNode* root;
    int size = 0;
    
    Solution(ListNode* head) {
        root = head;
        size = 0;
        
        ListNode* node = head;
        while (node) {
            ++size;
            node = node->next;
        }
    }
    
    int getRandom() {
        ListNode* node = root;
        int n    = rand()%size;
        for (int i = 0; i < n; ++i) {
            node = node->next;
        }
        
        return node->val;
    }
};
