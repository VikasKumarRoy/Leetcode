// Problem - 1339

// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

// O(n) time complexity and O(height) space complexity solution

class Solution {
public:
    int mod = 1e9 + 7;
    
    int getSum(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return root->val + getSum(root->left) + getSum(root->right);
    }
    
    long long dfs(TreeNode* root, long long& mx, int sum) {
        if(!root) {
            return 0;
        }
        long curr = root->val + dfs(root->left, mx, sum) + dfs(root->right, mx, sum);
        mx = max(mx, ;
        return curr;
    }
    
    int maxProduct(TreeNode* root) {
        int sum = getSum(root);
        int mx = 0;
        dfs(root, mx, sum);
        return mx;
    }
};