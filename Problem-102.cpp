//Problem - 102
// https://leetcode.com/problems/binary-tree-level-order-traversal/

// Time Complexity O(n) and O(n) space.

class Solution {
public:  
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        queue <TreeNode* > q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector <int> v;
            while(size--) {
                TreeNode *temp = q.front();
                v.push_back(temp->val);
                q.pop();
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};

