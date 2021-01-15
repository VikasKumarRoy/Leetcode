// Problem - 1646

// https://leetcode.com/problems/get-maximum-in-generated-array/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        vector <int> nums(n+1);
        int mx = 1;
        nums[1] = 1;
        for(int i = 2; i <= n; i++) {
            if(!(i&1))
                nums[i] = nums[i/2];
            else
                nums[i] = nums[i/2] + nums[i/2+1];
            mx = max(nums[i], mx);
        }
        return mx;
    }
};
