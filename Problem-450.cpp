//Problem - 450
// https://leetcode.com/problems/delete-node-in-a-bst/

// Passes all test cases O(h) complexity but worst case can go upto O(n)

class Solution {
public:
    
    TreeNode* minInRight(TreeNode* root) {
        while(root->left)
            root = root->left;
        return root;    
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        if(root->val > key)
            root->left = deleteNode(root->left, key);
        else if(root->val < key)
            root->right = deleteNode(root->right, key);
        else {
            if(!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if(!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* temp = minInRight(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};
   