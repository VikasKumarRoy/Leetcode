// Problem - 897

// https://leetcode.com/problems/increasing-order-search-tree/

// O(n) time complexity and O(n) space complexity solution using stack for inorder traversal

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)
            return NULL;
        stack <TreeNode* > s;
        TreeNode* curr = root, *prev, *head;
        head = prev = NULL;
        while(!s.empty() || curr) {
            while(curr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            if(!prev) {
                head = curr;
                prev = head;
            }
            else {
                prev->right = curr;
                prev->left = NULL;
                prev = curr;
            }
            curr = curr->right;
        }
        prev->left = prev->right = NULL;
        return head;    
    }
};
