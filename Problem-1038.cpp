// Problem - 1038

// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    int rightSum;
    
    void util(TreeNode* root) {
        if(!root)
            return;
        util(root->right);
        root->val += rightSum;
        rightSum = root->val;
        util(root->left);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        rightSum = 0;
        util(root);
        return root;
    }
};
