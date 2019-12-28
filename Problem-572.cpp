// Problem - 572

// https://leetcode.com/problems/subtree-of-another-tree/

// O(n*m) time complexity and O(n) space complexity solution

class Solution {
public:
    bool isSame(TreeNode *s, TreeNode *t) {
        if(!s && !t)
            return 1;
        if(!s || !t)
            return 0;
        return isSame(s->left, t->left) && isSame(s->right, t->right) && (s->val == t->val);
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s)
            return 0;
        if(s->val ==  t->val)
            if(isSame(s, t))
                return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};

// Another approach by postorder traversal

class Solution {
public:
    string inorder(TreeNode *s) {
        if(!s)
            return "$";
        return inorder(s->left) + " " + inorder(s->right) + " " + to_string(s->val) + " ";
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string str = inorder(s);
        string sub = inorder(t);
        if(str.find(sub) != string::npos)
            return true;
        return false;
    }
};