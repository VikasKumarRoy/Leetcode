// Problem - 1008

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

// O(n) time complexity and O(n) space complexity solution using stack

class Solution {
public:
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        stack <TreeNode*> s;
        TreeNode* root = new TreeNode(preorder[0]);
        s.push(root);
        for(int i = 1; i < n; i++) {
            if(preorder[i] < s.top()->val) {
                s.top()->left = new TreeNode(preorder[i]);
                s.push(s.top()->left);
            }
            else {
                TreeNode* temp = NULL;
                while(!s.empty() && s.top()->val < preorder[i]) {
                    temp = s.top();
                    s.pop();
                }
                temp->right = new TreeNode(preorder[i]);
                s.push(temp->right);
            }
        }
        return root;
    }
};

// O(n) time complexity and O(1) space ignoring stack space using recurssion 

class Solution {
public:
    
    int ind = 0;
    
    TreeNode* constructBST(vector<int>& preorder, int curr_max) { 
        if(ind >= preorder.size() || preorder[ind] > curr_max)
            return NULL;
        TreeNode *root = new TreeNode(preorder[ind++]);
        root->left = constructBST(preorder, root->val);
        root->right = constructBST(preorder, curr_max);
        return root;
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return constructBST(preorder, INT_MAX);
    }
};
