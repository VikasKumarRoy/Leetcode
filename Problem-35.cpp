// Problem - 35

// https://leetcode.com/problems/search-insert-position/

// O(logn) time complexity and O(1) space complexity solution using binary search

class Solution {
public:    
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n-1, mid = 0;
        if(target > nums[n-1])
            return n;
        while(l < h) {
            mid = (h-l)/2 + l;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                h = mid;
            else
                l = mid+1;
        }
        return l;
    }
};
