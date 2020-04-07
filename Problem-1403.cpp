// Problem - 1403

// https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/

// O(nlogn) time complexity and O(1) space complexity solution

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        int sum = 0;
        vector <int> ans;
        for(int i = nums.size()-1; i >= 0; i--) {
            sum += nums[i];
            ans.push_back(nums[i]);
            if(sum > totalSum/2)
                break;
        }
        return ans;
    }
};
