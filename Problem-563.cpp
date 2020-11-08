// Problem - 563

// https://leetcode.com/problems/binary-tree-tilt/

// O(n) time complexity and O(n) space complexity solution

class Solution {
    int sum = 0;
public:
    int findTiltHelper(TreeNode* root) {
        if(!root)
            return 0;
        int lv = findTiltHelper(root->left);
        int rv = findTiltHelper(root->right);
        sum += abs(lv - rv);
        return lv + rv + root->val;
    }
    
    int findTilt(TreeNode* root) {
        findTiltHelper(root);
        return sum;
    }
};
