// Problem-1143

// https://leetcode.com/problems/longest-common-subsequence/

// O(n*m) time complexity and O(m*n) space solution using DP

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector <vector<int>> dp(n+1, vector <int> (m+1, 0)); 
	    for(int i = 1; i < n+1; i++) {
	        for(int j = 1; j < m+1; j++) {
	            if(text1[i-1] == text2[j-1])
	                dp[i][j] = 1 + dp[i-1][j-1];
	            else
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	        }
        }
        return dp[n][m];
    }
};

// O(min(n, m)) space solution

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector <int> dp(m+1, 0);
	    for(int i = 0; i < n+1; i++) {
            vector <int> temp = dp;
	        for(int j = 1; j < m+1; j++) {
	            if(text1[i] == text2[j-1])
	                dp[j] = 1 + temp[j-1];
	            else
	                dp[j] = max(dp[j-1], temp[j]);
	        }
        }
        return dp[m];
    }
};
