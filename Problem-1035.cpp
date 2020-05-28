// Problem - 1035

// https://leetcode.com/problems/uncrossed-lines/

// O(n*m) time complexity and O(n*m) space complexity solution using dp similar to longest common subsequence

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vector <vector<int>> dp(n+1, vector <int> (m+1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(A[i-1] == B[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};