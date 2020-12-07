// Problem - 99

// https://leetcode.com/problems/recover-binary-search-tree/

// O(n) time complexity and O(n) space complexity solution using dfs

class Solution {
public:
    TreeNode *first = NULL, *second = NULL;
    TreeNode *prev = new TreeNode(INT_MIN);
    
    void util(TreeNode* root, TreeNode* prev) {
        if(!root)
            return;
        util(root->left);
        if(!first && root->val < prev->val)
            first = prev;
        if(first && root->val < prev->val)
            second = root;
        prev = root;
        util(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        util(root);
        swap(first->val, second->val);
    }
};

// OR O(n) time complexity and O(1) space complexity solution using Morris Traversal

class Solution {
public:
    TreeNode *first = NULL, *second = NULL;
    TreeNode *prev = new TreeNode(INT_MIN);
    
    void recoverTree(TreeNode* root) {
        if(!root)
            return;
        TreeNode* curr = root, *temp = NULL;
        while(curr) {
            if(curr->left == NULL) {
                if(!first && curr->val < prev->val)
                    first = prev;
                if(first && curr->val < prev->val)
                    second = curr;
                prev = curr;
                curr = curr->right;
            }
            else {
                temp = curr->left;
                while(temp->right && temp->right != curr) {
                    temp = temp->right;
                }
                // Create Link
                if(!temp->right) {
                    temp->right = curr;
                    curr =  curr->left;
                }
                // Restore Link
                else {
                    temp->right = NULL;
                    if(!first && curr->val < prev->val)
                        first = prev;
                    if(first && curr->val < prev->val)
                        second = curr;
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};
