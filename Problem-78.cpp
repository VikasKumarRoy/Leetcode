//Problem  - 78
// https://leetcode.com/problems/subsets/


// O(n*n) solution passes all tc

class Solution {
public:   
    void fun(vector<int>& nums, vector <vector<int>> &ans, int ind, vector <int> v) {
        ans.push_back(v);
        for(int i = ind; i < nums.size(); i++) {
            v.push_back(nums[i]);
            fun(nums, ans, i+1, v);
            v.pop_back();
        }   
    }    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector <int>> ans;
        if(nums.size() == 0)
            return ans;
        vector <int> v;
        fun(nums, ans, 0, v);
        return ans;
    }    
};


// By bit manipulation O(n^2) compexity

vector<vector<int>> subsets(vector<int>& nums) {
        int n = pow(2, nums.size());
        vector <vector <int>> ans(n);
        if(nums.size() == 0)
            return ans;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < n; j++) {
                if(j >> i & 1)
                    ans[j].push_back(nums[i]);
            }
        }
        return ans;
    } 