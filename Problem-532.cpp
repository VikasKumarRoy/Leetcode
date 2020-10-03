// Problem - 532

// https://leetcode.com/problems/k-diff-pairs-in-an-array/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set <int> us;
        unordered_set <string> ans;
        for(int i = 0; i < nums.size(); i++) {
            if(us.count(nums[i]-k))
                ans.insert(to_string(nums[i]-k)+'&'+to_string(nums[i]));
            if(us.count(nums[i]+k))
                ans.insert(to_string(nums[i])+'&'+to_string(nums[i]+k));
            us.insert(nums[i]);
        }
        return ans.size();
    }
};
