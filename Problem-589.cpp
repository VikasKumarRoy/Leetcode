// Problem - 589

// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

// O(n) time complexity and O(n) space complexity solution using recursion

class Solution {
public:
    void preOrderUtil(Node* root, vector <int>& ans) {
        if(!root)
            return;
        ans.push_back(root->val);
        for(auto child : root->children) {
            preOrderUtil(child, ans);
        }
    }
    
    vector<int> preorder(Node* root) {
        vector <int> ans;
        preOrderUtil(root, ans);
        return ans;
    }
};

//Iterative solution

class Solution {
public:
    
    vector<int> preorder(Node* root) {
        stack <Node*> s;
        vector <int> ans;
        if(!root)
            return ans;
        s.push(root);
        while(!s.empty()) {
            Node* temp = s.top();
            s.pop();
            ans.push_back(temp->val);
            for(auto it = temp->children.rbegin(); it != temp->children.rend(); it++)
                s.push(*it);
        }
        return ans;
    }
};

