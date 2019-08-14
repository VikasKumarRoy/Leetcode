//Problem  - 90
// https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    
    void fun(vector<int>& nums, vector <vector<int>> &ans, int ind, vector <int> v) {
        if(ind == nums.size()) {
            if(find(ans.begin(), ans.end(), v) == ans.end())
                ans.push_back(v);/
            return;
        }
        fun(nums, ans, ind+1, v);
        v.push_back(nums[ind]);
        fun(nums, ans, ind+1, v);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector <vector <int>> ans;
        if(nums.size() == 0)
            return ans;
        vector <int> v;
        sort(nums.begin(), nums.end());
        fun(nums, ans, 0, v);
        return ans;
    }
    
    
};