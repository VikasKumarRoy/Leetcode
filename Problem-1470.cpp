// Problem - 1470

// https://leetcode.com/problems/shuffle-the-array/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector <int> v;
        int i = 0;
        while(i < n) {
            v.push_back(nums[i]);
            v.push_back(nums[i+n]);
            i++;
        } 
        return v;
    }
};
