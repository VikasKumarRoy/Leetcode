//Problem - 617

// https://leetcode.com/problems/merge-two-binary-trees/

// O(n) time complexity and O(n) space complexity sol

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2)
            return NULL;
        int x = (t1 ? t1->val : 0) + (t2 ? t2->val : 0);
        TreeNode *temp = new TreeNode(x);
        temp->left = mergeTrees(t1 ? t1->left : NULL, t2 ? t2->left : NULL);
        temp->right = mergeTrees(t1 ? t1->right : NULL, t2 ? t2->right : NULL);
        return temp;
    }
};