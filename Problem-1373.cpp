// Problem - 1373

// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

// O(n) time complexity and O(n) space complexity solution postorder

class Solution {
public:
    
    struct RT {
        bool isBST = true;
        int max = INT_MIN;
        int min = INT_MAX;
        int sum = 0;
    }; 
        
    int ans = 0;
    
    RT maxSumBSTUtil(TreeNode* root) {
        RT rt;
        if(!root)
            return rt;
        RT lv = maxSumBSTUtil(root->left);
        RT rv = maxSumBSTUtil(root->right);
        if(lv.isBST && rv.isBST) {
            rt.isBST = root->val > lv.max && root->val < rv.min;
        }
        else
            rt.isBST = false;
        if(rt.isBST) {
            rt.max = max(rv.max, root->val);
            rt.min = min(lv.min, root->val);
            rt.sum = root->val + lv.sum + rv.sum;
        }
        else
            rt.sum = max(rv.sum, lv.sum);
        ans = max(ans, rt.sum);
        return rt;
    }    
    
    int maxSumBST(TreeNode* root) {
        maxSumBSTUtil(root);
        return ans;
    }
};

