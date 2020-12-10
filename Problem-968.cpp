// Problem - 968

// https://leetcode.com/problems/binary-tree-cameras/

// O(n) time complexity and O(n) space complexity solution using greedy approach

class Solution {
public:
    // 0 -> not monitred
    // 1 -> monitored no cam
    // 2 -> monitored with cam
    int cameras = 0;
    
    int utilGreedy(TreeNode* root) {
        if(!root) {
            return 1;
        }
        int lv = utilGreedy(root->left);
        int rv = utilGreedy(root->right);
        if(lv == 0 || rv == 0) {
            cameras++;
            return 2;
        }
        if(lv == 1 && rv == 1)
            return 0;
        return 1;
    }
    
    int minCameraCover(TreeNode* root) {
        int isMonitored = utilGreedy(root);
        if(isMonitored == 0)
            cameras++;
        return cameras;
    }
};
