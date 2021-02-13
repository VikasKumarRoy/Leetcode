// Problem - 1752

// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(; i < n-1; i++) {
            if(nums[i] > nums[i+1]) {
                break;
            }
        }
        i++;
        if(i == n)
            return true;
        int j = 0;
        while(j < n-1) {
            if(nums[(i+j)%n] > nums[(i+j+1)%n])
                return false;
            j++;
        }
        return true;
    }
};
