//Problem - 1262

// https://leetcode.com/problems/greatest-sum-divisible-by-three/

// O(n)  time complexity and O(1) space complexity sol

class Solution {
public:
    
    int maxSumDivThree(vector<int>& nums) {
        vector <int> dp(3, 0);
        for(int i = 0; i < nums.size(); i++) {
            vector <int> temp = dp;
            for(int j = 0; j < 3; j++)
                dp[(nums[i]+temp[j])%3] = max(dp[(nums[i]+temp[j])%3], nums[i]+temp[j]);
        }
        return dp[0];
    }
};