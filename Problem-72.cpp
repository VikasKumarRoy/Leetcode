// Problem - 72

// https://leetcode.com/problems/edit-distance/

// O(n*m) time complexity and O(n*m) space complexity solution using dp

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m =word2.length();
        vector <vector <int>> dp(n+1, vector <int> (m+1, 0));
        for(int i = 1; i <= n; i++)
            dp[i][0] = i;
        for(int j = 1; j <= m; j++)
            dp[0][j] = j;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
        return dp[n][m];
    }
};

// O(m) space solution

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m =word2.length();
        vector <int> dp(m+1, 0);
        for(int j = 1; j <= m; j++)
            dp[j] = j;
        for(int i = 0; i < n; i++) {
            int diag = dp[0];
            dp[0] = i+1;
            for(int j = 1; j <= m; j++) {
                int temp = dp[j];
                if(word1[i] == word2[j-1]) {
                    dp[j] = diag;
                }
                else {
                    dp[j] = 1 + min({dp[j-1], dp[j], diag});
                }
                diag = temp;
            }
        }
        return dp[m];
    }
};
