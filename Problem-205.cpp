// Problem - 205

// https://leetcode.com/problems/isomorphic-strings/

// O(n) time complexity and O(n) space complexity solution

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