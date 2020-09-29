// Problem - 713

// https://leetcode.com/problems/subarray-product-less-than-k/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int i = 0, j = 0;
        int prod = 1;
        while(j < nums.size()) {
            prod *= nums[j];
            while(i <= j && prod >= k)
                prod /= nums[i++];
            ans += j-i+1;
            j++;
        }
        return ans;
    }
};
