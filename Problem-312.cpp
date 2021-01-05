// Problem - 312

// https://leetcode.com/problems/burst-balloons/

// O(n^3) time complexity and O(n*n) space complexity solution

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int sz = nums.size();
        vector <vector <int>> dp(sz, vector <int> (sz, 0));
        for(int n = 0; n < sz; n++) {
            for(int i = 0; i+n < sz; i++) {
                int j = i+n;
                int leftNum = i == 0 ? 1 : nums[i-1];
                int rightNum = j == sz-1 ? 1 : nums[j+1];
                for(int k = i; k <= j; k++) {
                    int left = k == i ? 0 : dp[i][k-1];
                    int right = k == j ? 0 : dp[k+1][j];
                    dp[i][j] = max(dp[i][j], left + right + (leftNum*nums[k]*rightNum));
                }
            }
        }
        return dp[0][sz-1];
    }
};
