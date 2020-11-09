// Problem - 1026

// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

// O(n) time complexity and O(n) space complexity solution using bottom up dfs
 
class Solution {
public:
    int ans = 0;
    
    pair <int, int> maxDiff(TreeNode* root) {
        if(!root) {
            return {-1, 1e5+1};
        }
        if(!root->left && !root->right){
            return {root->val, root->val};
        }
        auto lv = maxDiff(root->left);
        auto rv = maxDiff(root->right);
        int mn = min(lv.second, rv.second);
        int mx = max(lv.first, rv.first);
        ans = max({ans, abs(mn - root->val), abs(mx - root->val)});
        mx = max(root->val, mx);
        mn = min(root->val, mn);
        return {mx, mn};
    }
    
    int maxAncestorDiff(TreeNode* root) {
        maxDiff(root);
        return ans;
    }
};
