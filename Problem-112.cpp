// Problem - 112

// https://leetcode.com/problems/path-sum/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    bool hasPathSumUtil(TreeNode* root, int sum, int currSum) {
        if(!root)
            return false;
        currSum += root->val;
        if(!root->left && !root->right && currSum == sum)
            return true;
        return hasPathSumUtil(root->left, sum, currSum) || hasPathSumUtil(root->right, sum, currSum);
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        return hasPathSumUtil(root, sum, 0);
    }
};
