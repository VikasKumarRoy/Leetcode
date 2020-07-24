// Problem - 797

// https://leetcode.com/problems/all-paths-from-source-to-target/

// O(2^n) time complexity and O(n) space complexity solution using dfs where n = no. of vertices.
// In worst case there could be 2^n paths.

class Solution {
public:
    vector <vector<int>> ans;
    
    void dfs(vector <vector<int>> graph, vector <int> &path, int u) {
        path.push_back(u);
        cout << u;
        if(u == graph.size()-1) {
            ans.push_back(path);
        }
        else {
            for(int v: graph[u]) {
                dfs(graph, path, v);
            }
        }
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> indegree(n);
        for(int u = 0; u < n; u++) {
            for(int v: graph[u]) {
                indegree[v]++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                vector <int> path;
                dfs(graph, path, i);
            }
        }
        return ans;
    }
};
