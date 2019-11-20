//Problem - 1261

// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/

// O(n) time complexity and O(1) time for search and O(n) space complexity sol

class FindElements {
public:
    unordered_set <int> us;
    
    void recover(TreeNode* root, int x) {
        if(!root)
            return;
        root->val = x;
        us.insert(x);
        if(root->left)
            recover(root->left, 2*x + 1);
        if(root->right)
            recover(root->right, 2*x + 2);
    }
    
    FindElements(TreeNode* root) {
        recover(root, 0);
    }
    
    bool find(int target) {
        return us.count(target);
    }
};
