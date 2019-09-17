//Problem - 101
// https://leetcode.com/problems/symmetric-tree/

// Time Complexity O(n) and O(1) space ignoring stack space

class Solution {
public:
    bool isIdentical(TreeNode *r1, TreeNode *r2)
    {
        if(r1==NULL && r2==NULL)
            return true;
        if(r1==NULL || r2==NULL)
            return false;
        
        bool lv = isIdentical(r1->left, r2->right);
        bool rv = isIdentical(r1->right, r2->left);
        return (lv&&rv&&r1->val == r2->val);
    }
    
    bool isSymmetric(TreeNode* root) {
        return isIdentical(root,root);
    }
};

