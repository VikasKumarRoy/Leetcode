// Problem - 103

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector <vector<int>> ans;
        queue <TreeNode*> q;
        q.push(root);
        bool lvl = 0;
        while(!q.empty()) {
            int sz = q.size();
            vector <int> v;
            while(sz--) {
                auto node = q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(lvl)
                reverse(v.begin(), v.end());
            lvl ^= 1;
            ans.push_back(v);
        }
        return ans;
    }
};
