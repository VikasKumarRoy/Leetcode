//Problem - 167
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

// Time Complexity O(n) and O(1) space complexity

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int st = 0;
        int en = nums.size()-1;
        while(st < en) {
            if(nums[st] + nums[en] < target)
                st++;
            else if(nums[st] + nums[en] > target)
                en--;
            else
                return {st+1, en+1};
        }
        return {};
    }
};


