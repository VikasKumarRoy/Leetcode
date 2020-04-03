// Problem - 53

// https://leetcode.com/problems/maximum-subarray/

// Time Complexity O(n) and O(1) space using hash table

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int gMax = nums[0], lMax = nums[0]; 
        for(int i = 1; i < nums.size(); i++) {
            lMax = max(nums[i], lMax+nums[i]);
            gMax = max(gMax, lMax);
        }
        return gMax;
    }
};


