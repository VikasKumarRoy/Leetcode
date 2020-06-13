// Problem - 368

// https://leetcode.com/problems/largest-divisible-subset/

// O(n^2) time complexity and O(n) space complexity solution using dp

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return {nums[0]};
        int mx = 0, ind = -1;
        sort(nums.begin(), nums.end());
        vector <int> dp(n, 1), pre(n);
        for(int i = 0; i < n; i++) {
            int k = -1;
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        k = j;
                    }
                }
            }
            pre[i] = k;
            if(dp[i] > mx) {
                mx = dp[i];
                ind = i;
            }
        }
        int i = ind;
        vector <int> ans;
        while(i != -1) {
            ans.push_back(nums[i]);
            i = pre[i];
        }
        return ans;
    }
};
