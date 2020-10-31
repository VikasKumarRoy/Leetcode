// Problem - 673

// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

// O(n^2) time complexity and O(n) space complexity solution

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0, ans = 0;
        vector <int> dp(n, 1);
        vector <int> ctr(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i] && dp[j]+1 >= dp[i]) {
                    if(dp[i] == dp[j] + 1) {
                        ctr[i] += ctr[j];
                    }
                    else {
                        dp[i] = dp[j]+1;
                        ctr[i] = ctr[j];
                    }
                }
            }
            if(dp[i] >= max_len) {
                if(dp[i] == max_len)
                    ans += ctr[i];
                else {
                    ans = ctr[i];
                    max_len = dp[i];
                }
            }
        }
        return ans;
    }
};
