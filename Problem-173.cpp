// Problem - 173

// https://leetcode.com/problems/binary-search-tree-iterator/

// O(n) time complexity and O(h) space complexity solution
// next() and hasNext() time complexity in average is O(1)

class BSTIterator {
public:
    stack <TreeNode*> s;
    
    BSTIterator(TreeNode* root) {
        while(root) {
            s.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode *curr = s.top();
        s.pop();
        int val = curr->val;
        if(curr->right) {
            curr = curr->right;
            while(curr) {
                s.push(curr);
                curr = curr->left;
            }
        }
        return val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};
