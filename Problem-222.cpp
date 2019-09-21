//Problem - 222
// https://leetcode.com/problems/count-complete-tree-nodes/

// Time Complexity O(n) and O(1) space ignoring stack space

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};

