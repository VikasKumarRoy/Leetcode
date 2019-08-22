//Problem  - 863
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// Passes all test cases O(n) time and space complexity  

class Solution {
public:
    
    unordered_map <TreeNode*, TreeNode*> parent;
    unordered_set <TreeNode* > visited;
    
    void parentNodeMap(TreeNode *root) {
        if(root == NULL)    return;
        if(parent.empty())
            parent[root] = NULL;
        if(root->left)  parent[root->left] = root;
        if(root->right) parent[root->right] = root;
        parentNodeMap(root->left);
        parentNodeMap(root->right);
    }
    
    vector <int> q_to_vec(queue <TreeNode*> q) {
        vector <int> v;
        while(!q.empty()) {
            TreeNode *data = q.front();
            v.push_back(data->val);
            q.pop();
        }
        return v;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        parentNodeMap(root);
        queue <TreeNode* > q;
        q.push(target);
        visited.insert(target);

        while(!q.empty() && K--) {
            int size = q.size();
            while(size--) {
                TreeNode* temp = q.front();
                q.pop();
                visited.insert(temp);
                if(visited.find(temp->left) == visited.end() && temp->left)
                    q.push(temp->left);
                if(visited.find(temp->right) == visited.end() && temp->right) 
                    q.push(temp->right);
                if(visited.find(parent[temp]) == visited.end() && parent[temp] !=NULL) 
                    q.push(parent[temp]);
            }
                
        }
            
        return q_to_vec(q);
    }
};