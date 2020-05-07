// Problem - 993

// https://leetcode.com/problems/cousins-in-binary-tree/

// O(n) time complexity and O(n) space complexity solution using BFS

class Solution {
public:
    
    bool isCousins(TreeNode* root, int x, int y) {
       queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            int ctr = 0;
            while(sz--) {
                TreeNode* curr = q.front();
                q.pop();
                TreeNode* lv = curr->left;
                TreeNode* rv = curr->right;
                int curr_ctr = 0;
                if(lv) {
                    q.push(lv);
                    if(lv->val == x || lv->val == y)
                        curr_ctr++;
                }
                if(rv) {
                    q.push(rv);
                    if(rv->val == x || rv->val == y)
                        curr_ctr++;
                }
                if(curr_ctr == 2)
                    return false;
                ctr += curr_ctr;
            }
            if(ctr == 2)
                return true;
        }
        return false;
    }
};
