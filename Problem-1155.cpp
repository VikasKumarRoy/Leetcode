//Problem  - 1155
// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/


// O(d * t * f) top down solution passes all tc

class Solution {
public:
    
    int mod = 1e9 + 7;
    
    int fun(int ind, int f, int d, int target, vector <vector <int>> &dp) {
        if(ind > f || d < 0 || target < 0)
            return 0;
        if(d == 0 && target == 0)
            return 1;
        if(dp[d][target] != -1)
            return dp[d][target];
        int ans = 0;
        for(int i = 1; i <= f; i++) {
             ans = (ans + fun(i, f, d-1, target-i, dp) % mod) % mod;
        }
        dp[d][target] = ans%mod;
        return dp[d][target];
    }
    
    int numRollsToTarget(int d, int f, int target) {
        vector <vector <int>> dp(d+1, vector <int> (target+1, -1));
        return fun(1, f, d, target, dp);
    }
};