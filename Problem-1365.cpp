// Problem - 1365

// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector <int> v(101, 0), ans(nums.size());
        for(int val : nums) {
            v[val]++;
        }
        for(int i = 1; i < 101; i++)
            v[i] += v[i-1];
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0)
                ans[i] = 0;
            else
                ans[i] = v[nums[i]-1];
        }
        return ans;
    }
};
