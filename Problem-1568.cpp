// Problem - 1568

// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/

// O(n*m*(v+edges)) time complexity and O(n*m) space complexity solution

class Solution {
public:
    int dirX[4] = {1, 0, -1, 0};
    int dirY[4] = {0, 1, 0, -1};

    bool isValid(int i, int j, vector <vector<int>>& grid) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
            return false;
        return true;
    }
    
    void floodFill(vector <vector<int>>& grid, int i, int j, int n, int m) {
        queue <pair <int, int>> q;
        q.push({i, j});
        grid[i][j] = 0;
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            for(int k = 0; k < 4; k++) {
                int xx = p.first + dirX[k];
                int yy = p.second + dirY[k];
                if(isValid(xx, yy, grid)) {
                    grid[xx][yy] = 0;
                    q.push({xx, yy});
                }
            }
        }
    }
    
    int countIsland(vector <vector<int>> grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    count++;
                    floodFill(grid, i, j, n, m);
                }
            }
        }
        return count;
    }
    
    int minDays(vector<vector<int>>& grid) {
        int island = countIsland(grid);
        if(island == 0 || island > 1)
            return 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    island = countIsland(grid);
                    if(island == 0 || island > 1)
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};
