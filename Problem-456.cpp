// Problem - 456

// https://leetcode.com/problems/132-pattern/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        int mn = min(nums[0], nums[1]);
        int mx = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++) {
            if(nums[i] < mx && nums[i] > mn)
                return true;
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        return false;
    }
};
