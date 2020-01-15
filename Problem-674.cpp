// Problem - 674

// https://leetcode.com/problems/longest-continuous-increasing-subsequence/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int ans = 1, ctr = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i-1])
                ctr++;
            else {
                ans = max(ans, ctr);
                ctr = 1;
            }
        }
        ans = max(ans, ctr);
        return ans;
    }
};