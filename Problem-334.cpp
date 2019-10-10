//Problem - 334
// https://leetcode.com/problems/increasing-triplet-subsequence/

// O(n) time complexity and O(1) space solution

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        int i = 0;
        int mid = INT_MAX;
        int j = 1;
        while(j < nums.size()) {
            if(nums[j] <= nums[i])
                i = j;
            else if(nums[j] > nums[i] && nums[j] < mid)
                mid = nums[j];
            else if(nums[j] > nums[i] && nums[j] > mid)
                return true;
            j++;
        }
        return false;
    }
};