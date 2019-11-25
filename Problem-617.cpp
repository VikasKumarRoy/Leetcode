//Problem - 617

// https://leetcode.com/problems/merge-two-binary-trees/

// O(n) time complexity and O(n) space complexity sol

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2)
            return NULL;
        TreeNode *temp = new TreeNode(10);
        temp->val = t1 ? t1->val : 0 + t2 ? t2->val : 0;
        temp->left = mergeTrees(t1->left, t2->left);
        temp->right = mergeTrees(t1->right, t2->right);
        return temp;
    }
};