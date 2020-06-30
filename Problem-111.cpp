//Problem  - 111

// https://leetcode.com/problems/minimum-depth-of-binary-tree/

// Passes all test cases O(n) time complexity 

class Solution {
public:
    int util(TreeNode* root) {
        if(!root)
            return INT_MAX;
        if(!root->left && !root->right)
            return 1;
        return min(util(root->left), util(root->right)) + 1;
    }
    
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        return util(root);
    }
};

// OR

class Solution {
public:   
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
        if(!root->left)
            return minDepth(root->right) + 1;
        if(!root->right)
            return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
