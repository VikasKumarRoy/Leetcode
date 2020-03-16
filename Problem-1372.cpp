// Problem - 1372

// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

// O(n) time complexity and O(n) space complexity solution 


class Solution {
public:
    struct RT{
        int l = 0;
        int r = 0;
    };
    
    int mx = 0;
    
    RT longestZigZagUtil(TreeNode* root) {
        RT rt;
        if(!root)
            return rt;
        if(root->right) {
            RT rv = longestZigZagUtil(root->right);
            rt.r = 1 + rv.l;
        }
        if(root->left) {
            RT lv = longestZigZagUtil(root->left);
            rt.l = 1 + lv.r;
        }
        mx = max(mx, max(rt.l, rt.r));
        return rt;
    } 
    
    int longestZigZag(TreeNode* root) {
        longestZigZagUtil(root);
        return mx;
    }
};

// OR using dfs

class Solution {
public:
    
    int mx = 0;
    
    void longestZigZagUtil(TreeNode* root, int l, int r) {
       if(!root)
           return;
        mx = max(mx, max(l, r));
        longestZigZagUtil(root->left, r+1, 0);
        longestZigZagUtil(root->right, 0, l+1);
    } 
    
    int longestZigZag(TreeNode* root) {
        longestZigZagUtil(root, 0, 0);
        return mx;
    }
};


