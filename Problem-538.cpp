// Problem - 538

// https://leetcode.com/problems/convert-bst-to-greater-tree/

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
    
    TreeNode* convertBST(TreeNode* root) {
        util(root);
        return root;
    }
};
