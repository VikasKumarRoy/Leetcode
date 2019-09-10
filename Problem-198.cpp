//Problem - 198
// https://leetcode.com/problems/house-robber/

// Time Complexity O(n)

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