// Problem - 1480

// https://leetcode.com/problems/running-sum-of-1d-array/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector <int> ans = nums;
        for(int i = 1; i < nums.size(); i++)
            ans[i] = ans[i] + ans[i-1];
        return ans;
    }
};
