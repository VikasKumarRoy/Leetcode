// Problem - 230

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// O(n) time complexity for construction and O(h) time for searching

struct Node {
    int val;
    Node *left, *right;
    int leftCount, totalCount;
    Node(int x) {
        val = x;
        left = right = NULL;
        leftCount = totalCount = 1;
    }
};

class Solution {
public:
    Node* buildMyTree(TreeNode *root) {
        if(!root)
            return NULL;
        Node *newNode = new Node(root->val);
        Node *lv = buildMyTree(root->left);
        Node *rv = buildMyTree(root->right);
        if(lv) {
            newNode->leftCount += lv->totalCount;
            newNode->totalCount += lv->totalCount;
        }
        if(rv)
            newNode->totalCount += rv->totalCount;
        newNode->left = lv;
        newNode->right = rv;
        return newNode;
    }
    
    int kthSmallestUtil(Node *root, int k) {
        if(k < 1 || k > root->totalCount)
            return -1;
        if(k == root->leftCount)
            return root->val;
        else if(k < root->leftCount) {
            return kthSmallestUtil(root->left, k);
        }
        else
            return kthSmallestUtil(root->right, k - root->leftCount);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        Node *newRoot = buildMyTree(root);
        return kthSmallestUtil(newRoot, k);
    }
};
