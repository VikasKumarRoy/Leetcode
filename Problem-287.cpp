// Problem - 287

// https://leetcode.com/problems/find-the-duplicate-number/

// O(nlogn) time complexity and O(1) space complexity solution using binary search

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, h = nums.size()-1;
        while(l < h) {
            int mid = (h-l)/2 + l;
            int count = 0;
            for(int val : nums) {
                if(val <= mid)
                    count++;
            }
            if(count > mid) {
                h = mid;
            }
            else
                l = mid+1;
        }
        return l;
    }
};
