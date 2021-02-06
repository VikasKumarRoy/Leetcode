// Problem - 209

// https://leetcode.com/problems/minimum-size-subarray-sum/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = n+1;
        int i = 0, j = 0;
        while(j < n) {
            if(sum < target) {
                sum += nums[j++];
            }
            while(i < j && sum >= target) {
                ans = min(ans, j-i);
                sum -= nums[i++];
            }            
        }
        return ans == n+1 ? 0 : ans;
    }
};
