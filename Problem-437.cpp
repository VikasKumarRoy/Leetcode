// Problem - 437

// https://leetcode.com/problems/path-sum-iii/

// O(n) time complexity and O(n) space complexity solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    
    void fun(TreeNode* root, int sum, vector<int> path, int sumTillNow) {
        
        if(root==NULL) return;
        
        path.push_back(root->val);
        
        sumTillNow+=root->val;
                
        if(root->right==NULL && root->left==NULL && sumTillNow==sum)
            ans.push_back(path);
        
        fun(root->left, sum, path, sumTillNow);
        fun(root->right, sum, path, sumTillNow);
        
    }
    
    int pathSum(TreeNode* root, int sum) {
        fun(root, sum, );
        return ans;
    }
};
