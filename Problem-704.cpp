// Problem - 704

// https://leetcode.com/problems/binary-search/

// O(logn) time complexity and O(1) space complexity solution

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size()-1;
        while(l <= h) {
            int mid = (h-l)/2 + l;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                l = mid+1;
            else
                h = mid-1;
        }
        return -1;
    }
};
