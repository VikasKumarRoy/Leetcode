// Problem - 113

// https://leetcode.com/problems/path-sum-ii/

// O(n) time complexity and O(n) space complexity solution using dfs

class Solution {
public:
    
    vector<vector<int>> ans;
    
    void fun(TreeNode* root, int sum, vector<int> path, int sumTillNow) {
        
        if(root==NULL) return;
        
        path.push_back(root->val);
        
        sumTillNow+=root->val;
                
        if(root->right==NULL && root->left==NULL && sumTillNow==sum)
            ans.push_back(path);
        
        fun(root->left, sum, path, sumTillNow);
        fun(root->right, sum, path, sumTillNow);
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        fun(root, sum, path, 0);
        return ans;
    }
    
};
