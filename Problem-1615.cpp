// Problem - 1615

// https://leetcode.com/problems/maximal-network-rank/

// O(n^2) time complexity and O(n) space complexity solution

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector <int> graph[n];
        for(auto road : roads) {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }
        int ans = 0;
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                int ctr = 0;
                ctr += (graph[i].size() + graph[j].size());
                for(auto v : graph[i]) {
                    if(v == j)
                        ctr--;
                }
                ans = max(ans, ctr);
            }
        }
        return ans;
    }
};
