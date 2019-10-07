//Problem - 1219
// https://leetcode.com/problems/path-with-maximum-gold/

// Time Complexity O(4^n*m) and O(1) space ignoring stack space

class Solution {
public:
    int corX[4] = {0, 1, -1, 0};
    int corY[4] = {1, 0, 0, -1};
    
    int dfs(vector<vector<int>> &grid, int n, int m, int i, int j) {
        if(i < 0 || j < 0 || i >= n || j >=m || grid[i][j] <= 0)
            return 0;
        int gold = 0;
        grid[i][j] = -grid[i][j];
        for(int k = 0; k < 4; k++) {
            int x = i + corX[k];
            int y = j + corY[k];
            gold = max(gold, dfs(grid, n, m, x, y));
        }
        grid[i][j] = -grid[i][j];
        return grid[i][j] + gold;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++)
                ans = max(ans, dfs(grid, n, m, i, j));
        return ans;
    }
};

