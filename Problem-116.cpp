// Problem - 116

// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

// O(n) time complexity and O(n) space complexity solution using recursion

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        if(root->left) {
            root->left->next = root->right;
            if(root->next)
                root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};

// OR O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        Node* curr, *pre = root;
        while(pre->left) {
            curr = pre;
            while(curr) {
                curr->left->next = curr->right;
                if(curr->next)  curr->right->next = curr->next->left;
                curr = curr->next;
            }
            pre = pre->left;
        }
        return root;
    }
};
