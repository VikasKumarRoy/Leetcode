// Problem - 1305

// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

// O(n+m) time complexity and O(n+m) space complexity solution

class Solution {
public:
    
    void inorder(TreeNode* root, vector <int>& v) {
        if(!root)
            return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        int i = 0, j = 0, k = 0;
        vector <int> tree1, tree2;
        inorder(root1, tree1);
        inorder(root2, tree2);
        int n = tree1.size(), m = tree2.size();
        vector <int> ans(n + m);
        while(i < n && j < m) {
            if(tree1[i] < tree2[j])
                ans[k++] = tree1[i++];
            else
                ans[k++] = tree2[j++];
        }
        while(i < n)
            ans[k++] = tree1[i++];
        while(j < m)
            ans[k++] = tree2[j++];
        return ans;
    }
};