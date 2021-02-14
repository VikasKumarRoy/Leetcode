// Problem - 1091

// https://leetcode.com/problems/shortest-path-in-binary-matrix/

// O(n*m) time complexity and O(n*m) space complexity solution usign bfs

class Solution {
public:
    int dirX[8] = {-1, -1, 0, 0, 1, 1, 1, -1};
    int dirY[8] = {-1, 1, 1, -1, -1, 1, 0, 0};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0] || grid[n-1][m-1])
            return -1;
        if(n == 1 && m == 1)
            return 1;
        vector <vector <int>> dist(n, vector <int> (m, INT_MAX));
        dist[0][0] = 1;
        queue <pair <int, int>> q;
        q.push({0, 0});
        int d = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto top = q.front();
                q.pop();
                int u = top.first, v = top.second;
                for(int i = 0; i < 8; i++) {
                    int x = u + dirX[i];
                    int y = v + dirY[i];
                    if(!(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 1)) {
                        if(d + 1 < dist[x][y]) {
                            dist[x][y] = d + 1;
                            if(x == n-1 && y == m-1)
                                return d+1;
                            q.push({x, y});
                        }
                    }
                }
            }
            d++;
        }
        return -1;
    }
};
