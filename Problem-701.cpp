// Problem - 701

// https://leetcode.com/problems/insert-into-a-binary-search-tree/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if(val > root->val)
            root->right = insertIntoBST(root->right, val);
        else
            root->left = insertIntoBST(root->left, val);
        return root;
    }
};
