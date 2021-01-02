// Problem - 1379

// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

// O(n) time complexity and O(n) space complexity solution using dfs

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!cloned)
            return NULL;
        if(original == target)
            return cloned;
        TreeNode* lv = getTargetCopy(original->left, cloned->left, target);
        TreeNode* rv = getTargetCopy(original->right, cloned->right, target);
        return lv ? lv : rv;
    }
};
