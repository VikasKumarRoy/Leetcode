// Problem - 1123

// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    TreeNode* findLCA(TreeNode* root, unordered_set <TreeNode*>& us) {
        if(!root)
            return root;
        if(us.count(root))
            return root;
        TreeNode* lv = findLCA(root->left, us);
        TreeNode* rv = findLCA(root->right, us);
        if(lv && rv)
            return root;
        return lv ? lv : rv;
    }
    
    int findMaxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return max(findMaxDepth(root->left), findMaxDepth(root->right)) + 1;
    }
    
    void getMaxDepthNode(TreeNode* root, int h, int maxH, unordered_set <TreeNode*>& us) {
        if(!root)
            return;
        if(h == maxH-1) {
            us.insert(root);
        }
        getMaxDepthNode(root->left, h+1, maxH, us);
        getMaxDepthNode(root->right, h+1, maxH, us);
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_set <TreeNode*> us;
        int maxDepth = findMaxDepth(root);
        getMaxDepthNode(root, 0, maxDepth, us);
        return findLCA(root, us);
    }
};

// Single Pass O(n) time complexity

class Solution {
public:
    
    pair <TreeNode*, int> helper(TreeNode* root) {
        if(!root)
            return {root, 0};
        pair <TreeNode*, int> lv = helper(root->left);
        pair <TreeNode*, int> rv = helper(root->right);
        if(lv.second == rv.second) {
            return {root, lv.second+1};
        }
        else if(lv.second > rv.second) {
            return {lv.first, lv.second+1};
        }
        else
            return {rv.first, rv.second+1};
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root).first;
    }
};
