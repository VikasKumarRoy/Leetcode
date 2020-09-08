// Problem - 1022

// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    int sum;
    
    void sumRootToLeafUtil(TreeNode* root, int val) {
        if(!root)
            return;
        val = val << 1;
        val += root->val;
        if(!root->left && !root->right) {
            sum += val;
        }
        sumRootToLeafUtil(root->left, val);
        sumRootToLeafUtil(root->right, val);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        sum = 0;
        sumRootToLeafUtil(root, 0);
        return sum;
    }
};
