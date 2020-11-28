// Problem - 416

// https://leetcode.com/problems/partition-equal-subset-sum/

// O(n*sum) time complexity and O(n*sum) space complexity solution

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int val : nums) {
            total += val;
        }
        if(total&1)
            return false;
        total /= 2;
        vector <vector <bool>> dp(n+1, vector <bool> (total+1, false));
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= total; j++) {
                dp[i][j] = dp[i-1][j];
                if(j >= nums[i-1]) {
                    dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][total];
    }
};
