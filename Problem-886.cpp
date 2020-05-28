// Problem - 886

// https://leetcode.com/problems/possible-bipartition/

// Time Complexity O(N + E) and O(N + E) space solution using graph coloring

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        if(dislikes.size() == 0)
            return true;
        vector <int> graph[N+1]; 
        vector <int> color(N+1, -1);
        for(auto p : dislikes) {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }
        queue <int> q;
        for(int i = 1; i <= N; i++) {
            if(color[i] != -1)
                continue;
            q.push(i);
            color[i] = 0;
            while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int v = q.front();
                q.pop();
                for(auto u: graph[v]) {
                    if(color[u] == color[v])
                        return false;
                    if(color[u] == -1) {
                        color[u] = !color[v];
                        q.push(u);
                    }
                }
            }
        }
        }
        
        return true;
    }
};
