// Problem - 435

// https://leetcode.com/problems/non-overlapping-intervals/

// O(n) time complexity and O(n) space complexity solution

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
