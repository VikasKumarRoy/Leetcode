// Problem - 189

// https://leetcode.com/problems/rotate-array/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k%n);
        reverse(nums.begin()+k%n, nums.end());
    }
};