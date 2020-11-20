// Problem - 81

// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

// O(logn) time complexity and O(1) space complexity solution

class Solution {
public:
    
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)
            return 0;
        int l = 0, h = n-1, mid;
        while(l <= h) {
            mid = (h-l)/2 + l;
            if(nums[mid] == target)
                return true;
            else if(nums[mid] < nums[h]) {
                if(nums[mid] < target && target <= nums[h]) {
                    l = mid+1;
                }
                else {
                    h = mid-1;
                }
            }
            else if(nums[mid] > nums[h]) {
                if(target >= nums[l] && target < nums[mid]) {
                    h = mid-1;
                }
                else {
                    l = mid+1;
                }
            }
            else {
                h--;
            }
        }
        return false;
    }
};
