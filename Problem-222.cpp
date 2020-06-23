// Problem - 222

// https://leetcode.com/problems/count-complete-tree-nodes/

// Time Complexity O(n) and O(1) space ignoring stack space

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};

//          OR

// O(logn*logn) time complexity O(1) space 

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        TreeNode *l, *r;
        l = r = root;
        int lh = 0, rh = 0;
        while(l) {
            lh++;
            l = l->left;
        }
        while(r) {
            rh++;
            r = r->right;
        }
        if(lh == rh) {
            //return pow(2, lh) - 1;       less efficient
            return (1 << lh) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
