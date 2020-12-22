// Problem - 110

// https://leetcode.com/problems/balanced-binary-tree/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    pair <bool, int> util(TreeNode* root) {
        if(!root)
            return {true, 0};
        pair <bool, int> lv = util(root->left);
        pair <bool, int> rv = util(root->right);
        int h = max(lv.second, rv.second)+1;
        bool isBalanced = lv.first && rv.first && (abs(lv.second-rv.second) < 2);
        return {isBalanced, h};
    }
    
    bool isBalanced(TreeNode* root) {
        return util(root).first;
    }
};
