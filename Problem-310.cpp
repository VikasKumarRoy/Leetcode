// Problem - 310

// https://leetcode.com/problems/minimum-height-trees/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector <int> adj[n];
        vector <int> ans;
        if(n == 1)
            return {0};
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector <int> leaves;
        for(int i = 0; i < n ; i++) {
            if(adj[i].size() == 1)
                leaves.push_back(i);
        }
        // Max possible MHT for n nodes can be upto 2
        while(n > 2) {
            n -= leaves.size();
            vector <int> newLeaves;
            for(int u : leaves) {
                for(auto v : adj[u]) {
                    auto it = find(adj[v].begin(), adj[v].end(), u);
                    adj[v].erase(it);
                    cout << adj[v].size();
                    if(adj[v].size() == 1) {
                        newLeaves.push_back(v);
                    }
                }
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};
