// Problem - 106

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

// O(n) time complexity and O(n) space complexity solution using dfs

class Solution {
public:
    unordered_map <int, int> um;
    
    TreeNode* dfs(vector <int>& inorder, vector<int>& postorder, int pos, int i, int j) {
        if(i > j || pos < 0)
            return NULL;
        TreeNode* root = new TreeNode(postorder[pos]);
        int f = um[postorder[pos]];
        root->right = dfs(inorder, postorder, pos-1, f+1, j);
        root->left = dfs(inorder, postorder, pos-(j-f+1), i, f-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++)
            um[inorder[i]] = i;
        return dfs(inorder, postorder, inorder.size()-1, 0, inorder.size()-1);
    }
};
