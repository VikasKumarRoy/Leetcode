//Problem - 1110
// https://leetcode.com/problems/delete-nodes-and-return-forest/

// Time Complexity O(n) and O(1) space ignoring stack space

class Solution {
public:
    unordered_set <int> toDel;
    vector <TreeNode*> ans;
    
    TreeNode* deleteNode(TreeNode* root) {
        if(!root)
            return NULL;
        root->left = deleteNode(root->left);
        root->right = deleteNode(root->right);
        if(toDel.find(root->val) != toDel.end()) {
            if(root->left)
                ans.push_back(root->left);
            if(root->right)
                ans.push_back(root->right);
            return NULL;
        }
        return root;     
    }
    
    vector <TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto i : to_delete)
            toDel.insert(i);
        TreeNode* temp = deleteNode(root);
        if(temp)    
            ans.push_back(root);
        return ans;
    }
};


