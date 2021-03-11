// Problem - 623

// https://leetcode.com/problems/add-one-row-to-tree/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    TreeNode* addToRowUtil(TreeNode* root, int v, int d, int dir) {
        if(d == 1) {
            TreeNode* node = new TreeNode(v);
            if(dir)
                node->right = root;
            else
                node->left = root;
            return node;
        }
        if(!root)
            return root;
        root->left = addToRowUtil(root->left, v, d-1, 0);
        root->right = addToRowUtil(root->right, v, d-1, 1);
        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1) {
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }
        root->left = addToRowUtil(root->left, v, d-1, 0);
        root->right = addToRowUtil(root->right, v, d-1, 1);
        return root;
    }
};
