// Problem - 153

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// O(logn) time complexity and O(1) space complexity solution

class Solution {
public:
    
    int findMin(vector<int>& nums) {
        int l = 0, h = nums.size()-1;
        while(l < h) {
            if(nums[l] < nums[h])
                return nums[l];
            int mid = (h-l)/2 + l;
            if(nums[mid] >= nums[l])
                l = mid+1;
            else
                h = mid;
        }
        return nums[l];
    }
};
