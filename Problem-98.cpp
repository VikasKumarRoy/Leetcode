//Problem  - 98
// https://leetcode.com/problems/validate-binary-search-tree/

// Passes all test cases O(n) time complexity 

class Solution {
public:
    
    struct RT{
        bool isBST = false;
        long long min = LLONG_MAX;
        long long max = LLONG_MIN;
    };
    
    long long min (long long a, long long b) {
        return (a < b ? a : b);
    }
    long long max (long long a, long long b) {
        return (a > b ? a : b);
    }
    
    RT isb(TreeNode* root) {
        
        RT rt;
        
        if(root==NULL){
            rt.isBST = true;
            return rt;
        }
        
        RT lv = isb(root->left);
        RT rv = isb(root->right);
        
        if(lv.isBST && rv.isBST) {
            rt.isBST = (lv.max < root->val && rv.min > root->val) ? true:false;
            rt.min = min(lv.min, root->val);
            rt.max = max(rv.max, root->val);
        }
        
        return rt;
    }
    
    bool isValidBST(TreeNode* root) {
        return isb(root).isBST;
    }
};