// Problem - 124

// https://leetcode.com/problems/binary-tree-maximum-path-sum/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    long long mx = LLONG_MIN;
    
    long long max(long long a, long long b)
    {
        return a > b ? a : b;
    }
    
    long long maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        long long lv = maxPathSum(root->left);
        long long rv = maxPathSum(root->right);
        
        mx = max(mx, max(root->val, max(root->val+lv+rv , max(root->val+lv, root->val+rv))));
        return mx;
    }
};
