// Problem - 637

// https://leetcode.com/problems/average-of-levels-in-binary-tree/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue <TreeNode*> q;
        q.push(root);
        vector <double> ans;
        while(!q.empty()) {
            int sz = q.size();
            int t = sz;
            double sum = 0;
            while(t--) {
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            ans.emplace_back(sum/sz);
        }
        return ans;
    }
};
