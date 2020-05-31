// Problem - 1464

// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

// Time Complexity O(n) and O(1) space complexity solutution

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = nums[0] > nums[1] ? nums[0] : nums[1];
        int s_mx = nums[0] < nums[1] ? nums[0] : nums[1];
        for(int i = 2; i < nums.size(); i++) {
            if(nums[i] >= mx) {
                s_mx = mx;
                mx = nums[i];
            }
            else if(nums[i] > s_mx)
                s_mx = nums[i];
        }
        return (--mx * --s_mx);
    }
};
