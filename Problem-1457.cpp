// Problem - 1457

// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    int ans = 0;
    
    bool isPseudoPalindromic(vector <int> v) {
        int odd = 0;
        for(int i = 0; i < 10; i++) {
            if(v[i]&1)
                odd++;
        }
        if(odd < 2)
            return true;
        return false;
    }
    
    void util(TreeNode* root, vector <int> v) {
        if(!root)
            return;
        v[root->val]++;
        if(!root->left && !root->right) {
            if(isPseudoPalindromic(v))
                ans++;
        }
        util(root->left, v);
        util(root->right, v);
        return;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector <int> v(10);
        util(root, v);
        return ans;
    }
};
