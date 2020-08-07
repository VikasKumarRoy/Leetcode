// Problem - 987

// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

// O(nlogn) time complexity and O(n) space complexity solution using dfs and map

class Solution {
public:
    void verticalUtil(TreeNode* root, int x, map <int, vector<pair<int, int>>> &m, int depth) {
        if(!root)
            return;
        m[x].push_back({depth, root->val});
        verticalUtil(root->left, x-1, m, depth+1);
        verticalUtil(root->right, x+1, m, depth+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map <int, vector <pair<int, int>>> m;
        vector <vector<int>> ans;
        verticalUtil(root, 0, m, 0);
        for(auto it : m) {
            auto v = it.second;
            sort(v.begin(), v.end());
            vector <int> temp;
            for(auto p : v)
                temp.push_back(p.second);
            ans.push_back(temp);
        }
        return ans;
    }
};
