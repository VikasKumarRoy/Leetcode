//Problem - 100
// https://leetcode.com/problems/same-tree/

// Time Complexity O(n) and O(1) space ignoring stack space

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(!p || !q)
            return false;
        bool lv = isSameTree(p->left, q->left);
        bool rv = isSameTree(p->right, q->right);
        return (p->val == q->val)&&lv&&rv;
    }
};

