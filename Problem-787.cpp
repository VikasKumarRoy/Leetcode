// Problem - 787

// https://leetcode.com/problems/cheapest-flights-within-k-stops/

// O(v+e) time complexity and O(e) space complexity solution using dfs

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector <pair <int,int>> graph[n];
        for(auto p : flights) {
            graph[p[0]].push_back({p[1], p[2]});
        }
        int ans = INT_MAX;
        stack <vector <int>>  s;
        s.push({src, K+1, 0});
        while(!s.empty()) {
            auto vec = s.top();
            int u = vec[0];
            int k = vec[1];
            int dist = vec[2];
            s.pop();
            if(k == 0)
                continue;
            for(auto v : graph[u]) {
                int d = dist + v.second;
                if(v.first == dst) {
                    ans = min(ans, d);
                } 
                if(d < ans)
                    s.push({v.first, k-1, d}); 
            }
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};
