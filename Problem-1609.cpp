// Problem - 1609

// https://leetcode.com/problems/even-odd-tree/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(!root)
            return false;
        queue <TreeNode*> q;
        q.push(root);
        int even = true;
        int prev = 1;
        while(!q.empty()) {
            int sz = q.size();
            bool first = true;
            while(sz--) {
                TreeNode* node = q.front();
                q.pop();
                if(even) {
                    if(!(node->val&1) || (!first && node->val <= prev))
                        return false;
                }
                else {
                    if(node->val&1 || (!first && node->val >= prev))
                        return false;
                }
                first = false;
                prev = node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            even ^= 1;
        }
        return true;
    }
};
