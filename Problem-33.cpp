// Problem - 33

// https://leetcode.com/problems/search-in-rotated-sorted-array/

// O(logn) time complexity and O(1) space complexity solution

class Solution {
public:
    int findPivot(vector<int>& nums, int l, int h) {
        if(l > h || nums[h] > nums[l])
            return -1;
        int mid = (h-l)/2 + l;
        if(mid != 0 && nums[mid-1] > nums[mid])
            return mid;
        else if(mid != nums.size()-1 && nums[mid+1] < nums[mid])
            return mid+1;
        return max(findPivot(nums, l, mid-1), findPivot(nums, mid+1, h));
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pv = max(0, findPivot(nums, 0, n-1));
        int l = 0, h = n-1;
        while(l <= h) {
            int mid = (h-l)/2 + l;
            int MID = (mid + pv)%n;
            if(nums[MID] == target)
                return MID;
            if(nums[MID] > target)
                h = mid-1;
            else
                l = mid+1;
        }
        return -1;
    }
};
