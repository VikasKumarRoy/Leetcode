// Problem - 152

// https://leetcode.com/problems/maximum-product-subarray/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int g_max = INT_MIN;
        int mx = 1, mn = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                mx = max(nums[i], mx * nums[i]);
                mn = min(nums[i], mn * nums[i]);
            }
            else if(nums[i] < 0) {
                int temp = mn;
                mn = min(nums[i], mx * nums[i]);
                mx = max(nums[i], temp * nums[i]);
            }
            else {
                mx = mn = nums[i];
            }   
            g_max = max(g_max, mx);
        }
        return g_max;
    }
};
