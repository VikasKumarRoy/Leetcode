// Problem - 337

// https://leetcode.com/problems/house-robber-iii/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    pair <int, int> robUtil(TreeNode* root) {
        if(!root) {
            return {0, 0};
        }
        pair <int, int> lv = robUtil(root->left);
        pair <int, int> rv = robUtil(root->right);
        int mx = max(root->val+lv.second+rv.second, lv.first+rv.first);
        return {mx, lv.first + rv.first};
    }
    
    int rob(TreeNode* root) {
        return robUtil(root).first;
    }
};
