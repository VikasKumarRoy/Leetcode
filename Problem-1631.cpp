// Problem - 1631

// https://leetcode.com/problems/path-with-minimum-effort/

// O(nmlog(nm)) time complexity and O(n*m) space complexity solution using dijkstra algo

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    int minimumEffortPath(vector<vector<int>>& height) {
        int n = height.size(), m = height[0].size();
        vector <vector <int>> dist(n, vector <int> (m, INT_MAX));
        priority_queue <pair <int, pair <int, int>>, vector <pair <int, pair <int, int>>>, greater<pair <int, pair <int, int>>> > pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        while(1) {
            int d = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            if(i == n-1 && j == m-1)
                return d;
            for(int k = 0; k < 4; k++) {
                int x = dx[k] + i;
                int y = dy[k] + j;
                if(x < n && y < m && x >= 0 && y >= 0) {
                    int mx = max(abs(height[i][j]-height[x][y]), d);
                    if(mx < dist[x][y]) {
                        dist[x][y] = mx;
                        pq.push({mx, {x, y}});
                    }
                }
            }
        }
        return -1;
    }
};
