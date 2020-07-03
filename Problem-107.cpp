// Problem - 107

// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

// O(n) time complexity and O(n) space complexity solution using dfs

class Solution {
public:
    int height(TreeNode* root) {
        if(!root)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    
    void dfs(TreeNode* root, int lvl, vector <vector<int>> &v, int h) {
        if(!root)
            return;
        v[h - lvl].push_back(root->val);
        dfs(root->left, lvl+1, v, h);
        dfs(root->right, lvl+1, v, h);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int h = height(root);
        vector <vector<int>> v(h);
        dfs(root, 0, v, --h);
        return v;
    }
};
