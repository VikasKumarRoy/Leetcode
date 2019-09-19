//Problem - 104
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

// Time Complexity O(n) and O(1) space ignoring stack space

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) +1;
        
    }
};

