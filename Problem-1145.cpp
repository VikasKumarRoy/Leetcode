//Problem  - 1145
// https://leetcode.com/problems/binary-tree-coloring-game/

class Solution {
public:
    
    int count(TreeNode* root) {
        if(!root)
            return 0;
        return count(root->left) + count(root->right) + 1;
    }
    
    TreeNode* find(TreeNode* root, int x) {
        if(!root)
            return NULL;
        if(root->val == x)
            return root;
        TreeNode* lv = find(root->left, x);
        TreeNode* rv = find(root->right, x);
        return lv ? lv : rv;
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if(n == 1)
            return false;
        TreeNode* temp = find(root, x);
        int lv = count(temp->left);
        int rv = count(temp->right);
        int par = n - lv - rv - 1;
        int mx = max(lv, max(rv, par));
        if(mx > n - mx)
            return true;
        return false;
    }
};