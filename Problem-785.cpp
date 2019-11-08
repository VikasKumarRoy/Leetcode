//Problem - 785

// https://leetcode.com/problems/is-graph-bipartite/

// O(n)  time complexity for dfs and O(n) space complexity sol

class Solution {
public:
    bool dfs(int col, int u, vector <int> &color, vector<vector<int>>& graph) {
        if(color[u] != 0) {
            return color[u] == col ? 1 : 0;
        }
        color[u] = col;
        for(int i = 0; i < graph[u].size(); i++) {
            if(!dfs(-col, graph[u][i], color, graph))
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector <int> color(graph.size(), 0);
        for(int i = 0; i < graph.size(); i++) {
            if(color[i] == 0 && !dfs(1, i, color, graph))
                return false;
        }
        return true;
    }
};
