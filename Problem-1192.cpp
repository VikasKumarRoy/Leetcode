// Problem - 1192

// https://leetcode.com/problems/critical-connections-in-a-network/

// O(v+e) time complexity and O(n) space complexity solution

class Solution {
public:
    int time = 0;
    vector <vector <int>> ans;
    
    void dfs(vector <int> adj[], vector <int>& disc, vector <int>& low, int u, vector <int>& parent) {
        disc[u] = low[u] = ++time;
        for(int v : adj[u]) {
            if(disc[v] == -1) {
                parent[v] = u;
                dfs(adj, disc, low, v, parent);
                low[u] = min(low[u], low[v]);
                if(low[v] > disc[u])
                    ans.push_back({u, v});
            }
            else if(parent[u] != v)
                low[u] = min(low[u], disc[v]);
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector <int> adj[n];
        for(auto path : connections) {
            adj[path[0]].push_back(path[1]);
            adj[path[1]].push_back(path[0]);
        }
        vector <int> disc(n, -1), low(n, 0), parent(n, -1);
        for(int i = 0; i < n; i++) {
            if(disc[i] == -1)
                dfs(adj, disc, low, i, parent);
        }
        return ans;
    }
};
