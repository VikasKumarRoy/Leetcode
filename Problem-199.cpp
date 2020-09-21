// Problem - 199

// https://leetcode.com/problems/binary-tree-right-side-view/

// O(n) time complexity and O(n) space complexity solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector <int> ans;
    int mxLvl = -1;
    
    void rightSideUtil(TreeNode* root, int lvl) {
        if(!root)
            return;
        if(lvl > mxLvl) {
            mxLvl = lvl;
            ans.push_back(root->val);
        }
        rightSideUtil(root->right, lvl+1);
        rightSideUtil(root->left, lvl+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        rightSideUtil(root, 0);
        return ans;
    }
};
