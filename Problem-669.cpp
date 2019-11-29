//Problem - 669

// https://leetcode.com/problems/trim-a-binary-search-tree/

// O(n)  time complexity and O(n) space complexity sol

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root)
            return NULL;
        if(root->val >= L && root->val <= R) {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;
        }
        else if(root->val < L) {
            return trimBST(root->right, L, R); 
        }
        else {
            return trimBST(root->left, L, R); 
        }
        
    }
};