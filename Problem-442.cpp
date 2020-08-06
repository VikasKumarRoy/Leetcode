// Problem - 442

// https://leetcode.com/problems/find-all-duplicates-in-an-array/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int> ans;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[abs(nums[i])-1] < 0)
                ans.push_back(abs(nums[i]));
            else
                nums[abs(nums[i])-1] *= -1;
        }
        return ans;
    }
};
