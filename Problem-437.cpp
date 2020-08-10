// Problem - 437

// https://leetcode.com/problems/path-sum-iii/

// O(n) time complexity and O(n) space complexity solution using dfs

class Solution {
public:
    int ans = 0;
    
    void util(TreeNode* root, int sum, unordered_map <int, int> um, int currSum) {
        if(!root)
            return;
        currSum += root->val;
        if(um.count(currSum - sum))
            ans += um[currSum - sum];
        um[currSum]++;
        util(root->left, sum, um, currSum);
        util(root->right, sum, um, currSum);
    }
    
    int pathSum(TreeNode* root, int sum) {
        unordered_map <int, int> um;
        um[0]++;
        util(root, sum, um, 0);
        return ans;
    }
};
