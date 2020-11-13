// Problem - 47

// https://leetcode.com/problems/permutations-ii/

// O(n!) time complexity and O(n) space complexity solution

class Solution {
public:
    void backtrack(vector <int> nums, int pos, vector <vector<int>>& ans) {
        if(pos == nums.size()-1) {
            ans.push_back(nums);
            return;
        }
        for(int i = pos; i < nums.size(); i++) {
            if(i != pos && nums[i] == nums[pos])
                continue;
            swap(nums[pos], nums[i]);
            backtrack(nums, pos+1, ans);
            // swap(nums[pos], nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector <vector <int>> ans;
        backtrack(nums, 0, ans);
        return ans;
    }
};
