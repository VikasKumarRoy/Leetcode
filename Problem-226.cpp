//Problem - 226
// https://leetcode.com/problems/invert-binary-tree/

// Time Complexity O(n) and O(n) space for call stack

class Solution {

public:
    
    void swap(int *a, int *b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        TreeNode *lv = invertTree(root->left);
        TreeNode *rv = invertTree(root->right);
        root->left = rv;
        root->right = lv;
        return root;
        
    }
};

