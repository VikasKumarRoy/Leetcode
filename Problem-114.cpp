// Problem - 114

// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

// O(n) time complexity and O(n) space complexity solution using stack

class Solution {
public:
    
    void flatten(TreeNode* root) {
        if(!root)
            return;
        stack <TreeNode*> s;
        s.push(root);
        TreeNode* prev = NULL;
        while(!s.empty()) {
            auto curr = s.top();
            s.pop();
            if(curr->right) {
                s.push(curr->right);
            }
            if(curr->left) {
                s.push(curr->left);
            }
            if(prev) {
                prev->right = curr;
                prev->left = NULL;
            }
            prev = curr;
        }
    }
};

//                        OR
// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    
    void flatten(TreeNode* root) {
        if(!root)
            return;
        TreeNode* curr = root;
        while(curr) {
            if(curr->left) {
                TreeNode* temp = curr->left;
                while(temp->right) {
                    temp = temp->right;
                }
                temp->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
