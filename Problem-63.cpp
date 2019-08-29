//Problem - 63
// https://leetcode.com/problems/unique-paths-ii/

// O(n * m) solution using dp with O(n * m) space

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        int n = grid.size(), m = grid[0].size();
        vector <vector <long>> dp(n, vector <long> (m, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1)
                    dp[i][j] = -1;
            }
        dp[0][0] = grid[0][0] == 0 ? 1 : -1;
        for(int i = 1; i < n; i++)
            dp[i][0] = dp[i-1][0] == -1 || dp[i][0] == -1 ? -1 : 1;
        for(int i = 1; i < m; i++)
            dp[0][i] = dp[0][i-1] == -1 || dp[0][i] == -1 ? -1 : 1;
        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++) {
                if(dp[i][j] != -1) {
                    if(dp[i-1][j] != -1)
                        dp[i][j] += dp[i-1][j];
                    if(dp[i][j-1] != -1)
                        dp[i][j] += dp[i][j-1];
                }
            }
        return dp[n-1][m-1] == -1 ? 0 : dp[n-1][m-1];
    }
};
   