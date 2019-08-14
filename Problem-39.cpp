//Problem  - 39
// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    void fun(int ind, vector<int>& candidates, vector <vector <int>> &ans, vector <int> v, int target) {
        if(target == 0) {
            ans.push_back(v);
            return;
        }
        if(target < 0)
            return;
        for(int i = ind; i < candidates.size(); i++) {
            if(target < candidates[i])
                break;
            v.push_back(candidates[i]);
            fun(i, candidates, ans, v, target - candidates[i]);
            v.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <vector <int>> ans;
        vector <int> v;
        sort(candidates.begin(), candidates.end());
        fun(0, candidates, ans, v, target);
        return ans;
    }
};