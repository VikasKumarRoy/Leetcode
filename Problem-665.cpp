// Problem - 665

// https://leetcode.com/problems/non-decreasing-array/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool flag = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i-1]) {
                if(flag)
                    return 0;
                flag = 1;
            }
        }
        return 1;
    }
};