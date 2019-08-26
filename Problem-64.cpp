//Problem - 64
// https://leetcode.com/problems/minimum-path-sum/

// Recursive solution O(2^n)

class Solution {
public:
    
    int fun(vector <vector<int>> grid, int i, int j) {
        if(i >= grid.size() || j >= grid[0].size())
            return INT_MAX;
        if(i == grid.size()-1 && j == grid[0].size()-1)
            return grid[i][j];
        int a = fun(grid, i+1, j);
        int b = fun(grid, i, j+1);
        return min(a, b) +  grid[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        return fun(grid, 0, 0);
    }
};

// Top Down Memorisation method O(m*n)

class Solution {
public:
    
    int fun(vector <vector<int>> grid, int i, int j, vector <vector <int>> &dp) {
        if(i >= grid.size() || j >= grid[0].size())
            return INT_MAX;
        if(i == grid.size()-1 && j == grid[0].size()-1)
            return grid[i][j];
        if(dp[i][j] == -1) {
            int a = fun(grid, i+1, j, dp);
            int b = fun(grid, i, j+1, dp);
            dp[i][j] = min(a, b) +  grid[i][j];
        }
        return dp[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        vector <vector <int>> dp(grid.size(), vector <int> (grid[0].size(), -1));
        return fun(grid, 0, 0, dp);
    }
};

// Bottom Up Tabulation method O(m*n) passes all tc

class Solution {
public:
        
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        int n = grid.size(), m = grid[0].size();
        vector <vector <int>> dp(n, vector <int> (m, 0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < n; i++)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int i = 1; i < m; i++)
            dp[0][i] = dp[0][i-1] + grid[0][i];
        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        return dp[n-1][m-1];
    }
};

   