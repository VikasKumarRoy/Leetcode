// Problem - 229

// https://leetcode.com/problems/majority-element-ii/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return {};
        int maj1 = nums[0], ctr1 = 1, ctr2 = 0;
        long maj2 = LONG_MIN;
        vector <int> ans;
        for(int i = 1; i < n; i++) {
            if(nums[i] == maj1)
                ctr1++;
            else if(nums[i] == maj2)
                ctr2++;
            else if(ctr1 == 0) {
                ctr1 = 1;
                maj1 = nums[i];
            }
            else if(ctr2 == 0) {
                ctr2 = 1;
                maj2 = nums[i];
            }
            else {
                ctr1--;
                ctr2--;
            }
        }
        ctr1 = ctr2 = 0;
        for(int val : nums) {
            if(val == maj1)
                ctr1++;
            if(val == maj2)
                ctr2++;
        }
        if(ctr1 > n/3)
            ans.push_back(maj1);
        if(ctr2 > n/3)
            ans.push_back(maj2);
        return ans;
    }
};
