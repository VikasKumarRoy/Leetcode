// Problem - 1007

// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        if(root->left) {
            if(root->right) {
                root->left->next = root->right;
            }
            else {
                Node* curr = root->next;
                while(curr) {
                    if(curr->left) {
                        root->left->next = curr->left;
                        break;
                    }
                    if(curr->right) {
                        root->left->next = curr->right;
                        break;
                    }
                    curr = curr->next;
                }
            }
        }
        if(root->right) {
            Node* curr = root->next;
            while(curr) {
                cout << curr->val << " ";
                if(curr->left) {
                    root->right->next = curr->left;
                    break;
                }
                if(curr->right) {
                    root->right->next = curr->right;
                    break;
                }
                curr = curr->next;
            }
            cout <<endl;
        }
        connect(root->right);
        connect(root->left);
        return root;
    }
};
