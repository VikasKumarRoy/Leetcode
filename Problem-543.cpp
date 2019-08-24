//Problem  - 543
// https://leetcode.com/problems/diameter-of-binary-tree/

// Passes all test cases O(n) complexity

class Solution {
public:
    
    struct RT{
        int h = 0;
        int d = 0;
    };
    
    
    RT myDia(TreeNode* root) {
        RT rt;
        if(!root) {
            return rt; 
        }
        RT lv = myDia(root->left);
        RT rv = myDia(root->right);
        rt.h = max(lv.h, rv.h) + 1;
        rt.d = max(lv.d, max(rv.d, lv.h + rv.h));
                   return rt;
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        return myDia(root).d;
        
        
    }
};
   