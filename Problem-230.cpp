 
// Problem - 230

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// O(n) time complexity for construction and O(h) time for serching

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct Node {
    int val;
    Node *left, right;
    int count;
    Node(int x) {
        val = x;
        left = right = NULL;
        count = 1;
    }
};

class Solution {
public:
    Node* buildMyTree(root) {
        if(!root)
            return NULL;
        
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
        buildMyTree(root);
    }
};
