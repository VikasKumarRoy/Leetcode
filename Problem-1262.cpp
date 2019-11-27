//Problem - 1262

// https://leetcode.com/problems/greatest-sum-divisible-by-three/

// O(n)  time complexity and O(1) space complexity sol

class Solution {
public:
    
    int maxSumDivThree(vector<int>& nums) {
        vector <vector<int>> dp(nums.size()+1, vector <int> (3, 0));
        for(int i = 1; i < nums.size()+1; i++) {
            for(int j = 0; j < 3; j++) {
                dp[i][(nums[i-1]+dp[i-1][j])%3] = max(dp[i-1][(nums[i-1]+dp[i-1][j])%3],)
            }
        }
        return dp[0][nums.size()];
    }
};