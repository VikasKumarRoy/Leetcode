//Problem - 235
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

// Time Complexity O(n) and O(1) space ignoring stack space

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        TreeNode *rv = NULL;
        TreeNode *lv = NULL;
        if(p->val > root->val && q->val > root->val)
            return rv = lowestCommonAncestor(root->right, p, q);
        else if(p->val < root->val && q->val < root->val)
            return lv = lowestCommonAncestor(root->left, p, q);
        else
            return root;
    }
};

