//Problem  - 46
// https://leetcode.com/problems/permutations/

class Solution {
public:
    
    void fun(vector<int>& nums, vector <vector <int>> &ans, vector <int> v) {
        if(v.size() == nums.size()) {
            ans.push_back(v);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(find(v.begin(), v.end(), nums[i]) != v.end())
                continue;
            v.push_back(nums[i]);
            fun(nums, ans, v);
            v.pop_back();
        }
    }
    
    vector <vector<int>> permute(vector<int>& nums) {
        vector <vector <int>> ans;
        if(!nums.size())
            return ans;
        vector <int> v;
        fun(nums, ans, v);
        return ans;
    }    
};