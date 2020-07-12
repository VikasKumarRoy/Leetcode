// Problem - 662

// https://leetcode.com/problems/maximum-width-of-binary-tree/

// O(n) time complexity and O(n) space complexity solution using bfs 

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue <pair <TreeNode*, int>> q;
        q.push({root, 1});
        int ans = 1;
        while(!q.empty()) {
            int sz = q.size();
            int offset = q.front().second;
            ans = max(ans, (q.back().second - offset + 1));
            while(sz--) {
                TreeNode* node = q.front().first;
                int pos = q.front().second - offset;
                q.pop();
                if(node->left)
                    q.push({node->left, 2*pos});
                if(node->right)
                    q.push({node->right, 2*pos+1});
            }
        }
        return ans;
    }
};
