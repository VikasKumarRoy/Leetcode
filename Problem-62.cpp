//Problem - 62
// https://leetcode.com/problems/unique-paths/

// O(n * m) solution using dp with O(n * m) space

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector <vector <int>> dp(n, vector <int> (m, 0));
        dp[0][0] = 1;
        for(int i = 1; i < n; i++)
            dp[i][0] = 1;
        for(int i = 1; i < m; i++)
            dp[0][i] = 1;
        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        return dp[n-1][m-1];
    }
};

// O(n * m) solution using dp with O(m) space

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector <int> dp(m, 1);
        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++) {
                dp[j] += dp[j-1];
            }
        return dp[m-1];
    }
};
   