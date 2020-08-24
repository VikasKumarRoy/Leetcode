// Problem - 404

// https://leetcode.com/problems/sum-of-left-leaves/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    
    int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
        if(!root)
            return 0;
        if(!root->left && !root->right && isLeft)
            return root->val;
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right);
    }
};
