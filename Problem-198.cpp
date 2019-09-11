//Problem - 198
// https://leetcode.com/problems/house-robber/

// Time Complexity O(n) using top down(memorization)

class Solution {
public:
    int getMaxSequence(vector <int> v, int ind, vector <int> &dp) {
    if(ind >= v.size())
        return 0;
    if(dp[ind] != -1)
        return dp[ind];
    int a = getMaxSequence(v, ind+1, dp);
    int b = v[ind] + getMaxSequence(v, ind+2, dp);
    dp[ind] = max(a, b);
    return dp[ind];
}
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        vector <int> dp(nums.size(), -1);
        return getMaxSequence(nums, 0, dp);
    }
};

// Bottom UP

class Solution {
public:
        int rob(vector<int>& nums) {
            if(nums.empty())
                return 0;
            if(nums.size() == 1) {
                return nums[0];
            }
            vector <int> dp(nums.size());
            dp[0] = nums[0];
            dp[1] = max(nums[1], nums[0]);
            for(int i = 2; i < nums.size(); i++)
                dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
            return dp[nums.size() - 1];
        }
};