//Problem - 300
// https://leetcode.com/problems/longest-increasing-subsequence/

// O(2^n) time complexity and O(n^2) space solution gives TLE

class Solution {
public:
    int getLIS(vector <int> nums, int ind, int len, int lastEle) {
        if(ind >= nums.size())
            return len;
        int a = 0, b = 0;
        if(nums[ind] > lastEle)
            a = getLIS(nums, ind+1, len+1, nums[ind]);
        b = getLIS(nums, ind+1, len, lastEle);
        return max(a, b);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        return getLIS(nums, 0, 0, INT_MIN);
    }
};

// O(n^2) time complexity and O(n) space solution using dp passes all TC

class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        vector <int> dp(n);
        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            dp[i] = 1;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i] && dp[j]+1 > dp[i])
                    dp[i] = dp[j] + 1; 
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};