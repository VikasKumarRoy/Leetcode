// Problem - 540

// https://leetcode.com/problems/single-element-in-a-sorted-array/

// O(logn) time complexity and O(1) space complexity solution binary search

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, h = nums.size()-1;
        while(l < h) {
            int mid = (h-l)/2 + l;
            cout << mid << " ";
            if(mid & 1) {
                int prev = mid > 0 ? nums[mid-1] : -1;
                if(nums[mid] == prev)
                    l = mid+1;
                else
                    h = mid;
            }
            else {
                int next = mid < nums.size()-1 ? nums[mid+1] : -1;
                if(nums[mid] == next)
                    l = mid+1;
                else
                    h = mid;
                
            }
        }
        return nums[l];
    }
};
