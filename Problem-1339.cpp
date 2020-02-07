// Problem - 1339

// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    int mod = 1e9 + 7;
    
    int dfsSum(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return root->val + dfsSum(root->left) + dfsSum(root->right);
    }
    
    int dfs(TreeNode* root, int& mx, int sum) {
        if(!root) {
            return 0;
        }
        int curr = root->val + dfs(root->left, mx, sum) + dfs(root->right, mx, sum);
        mx = max(mx, ((curr%mod)*(sum-curr)%mod)%mod);
        return curr;
    }
    
    int maxProduct(TreeNode* root) {
        int sum = dfsSum(root);
        int mx = 0;
        dfs(root, mx, sum);
        return mx;
    }
};