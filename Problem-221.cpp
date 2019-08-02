//Problem - 221
// https://leetcode.com/problems/maximal-square/

//Recursion Solution
class Solution {
public:
    int getMaxSquare(vector <vector <char>> v, int i, int j) {
        if(i >= v.size() || j >= v[0].size() || v[i][j] == '0')
            return 0;
        int x = getMaxSquare(v, i+1, j);
        int y = getMaxSquare(v, i, j+1);
        int z = getMaxSquare(v, i+1, j+1);
        return 1 + min(x, min(y, z));
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[i].size(); j++) {
                ans = max(ans, getMaxSquare(matrix, i, j, dp));
            }
        return ans*ans;
    }
};

//Memorization(Top Down)
class Solution {
public:
    int getMaxSquare(vector <vector <char>> v, int i, int j, vector <vector <int>> &dp) {
        if(i >= v.size() || j >= v[0].size() || v[i][j] == '0')
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int x = getMaxSquare(v, i+1, j, dp);
        int y = getMaxSquare(v, i, j+1, dp);
        int z = getMaxSquare(v, i+1, j+1, dp);
        dp[i][j] = 1 + min(x, min(y, z));
        return dp[i][j];
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector <vector <int>> dp(matrix.size(), vector <int> (matrix[0].size(), -1));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                ans = max(getMaxSquare(v, i, j, dp), ans);
            }
        return ans * ans;
    }
};

//Tabulation(Bottom Up) with O(n) space

class Solution {
public:
    
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
    
        vector <int> dp(m, 0), temp(m, 0);
        for(int i = 0; i < m; i++) {
            dp[i] = matrix[0][i] - '0';
            ans = max(dp[i], ans);
        }
        for(int i = 0; i < n; i++)
            ans = max(matrix[i][0]-'0', ans);

        for(int i = 1; i < n; i++) {
            temp = dp;
            dp[0] = matrix[i][0] - '0';
            for(int j = 1; j < m; j++) {
                int t = dp[j];
                if(matrix[i][j] == '1')
                    dp[j] = 1 + min(dp[j-1], min(temp[j-1], temp[j]));
                else
                    dp[j] = 0;
                ans = max(dp[j], ans);
            }
        }
        return ans * ans;
    }
};