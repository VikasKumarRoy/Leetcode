//Problem - 700

// https://leetcode.com/problems/search-in-a-binary-search-tree/

// O(n) time complexity and O(n) space complexity sol

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return NULL;
        if(root->val == val)
            return root;
        if(root->val < val)
            return searchBST(root->right, val);
        else
            return  searchBST(root->left, val);
    }
};
