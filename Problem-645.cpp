// Problem - 645

// https://leetcode.com/problems/set-mismatch/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set <int> us;
        int repeated = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(us.count(nums[i])) {
                repeated = nums[i];
            }
            us.insert(nums[i]);
        }
        for(int i = 1; i <= nums.size(); i++) {
            if(!us.count(i)) {
                return {repeated, i};
            }
        }
        return {-1, -1};
    }
};
