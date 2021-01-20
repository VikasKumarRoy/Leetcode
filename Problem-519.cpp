// Problem - 519

// https://leetcode.com/problems/longest-palindromic-subsequence/

// O(n^2) time complexity and O(n^2) space complexity solution using bottom up dp

class Solution {
public:
    
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector <vector <int>> dp(n, vector <int> (n, 0));
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for(int len = 1; len < n; len++) {
            for(int j = 0; j + len < n; j++) {
                if(s[j] == s[j+len]) {
                    dp[j][j+len] = dp[j+1][j+len-1] + 2;
                }
                else
                    dp[j][j+len] = max(dp[j+1][j+len], dp[j][j+len-1]);
            }
        }
        return dp[0][n-1];
    }
};
