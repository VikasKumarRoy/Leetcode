// Problem - 96

// https://leetcode.com/problems/unique-binary-search-trees/

// O(n*n) time complexity and O(n) space complexity solution using dp similar to catalan numbers

class Solution {
public:
    int numTrees(int n) {
        vector <int> dp(n+1);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};
