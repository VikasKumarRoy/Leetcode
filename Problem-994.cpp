// Problem - 994

// https://leetcode.com/problems/rotting-oranges/

// O(n*m) time complexity and O(n*m) space complexity solution using bfs

class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
        
    bool isValid(int x, int y, int n, int m) {
        return x < n && x >=0 && y < m && y >= 0; 
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0, fresh = 0;
        queue <pair <int, int>> q;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        while(!q.empty() && fresh > 0) {
            ans++;
            int sz = q.size();
            while(sz--) {
                auto p = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int x = p.first + dx[i];
                    int y = p.second + dy[i];
                    if(isValid(x, y, grid.size(), grid[0].size()) && grid[x][y] == 1) {
                        fresh--;
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }
        }
        return fresh == 0 ? ans : -1;
    }
};
