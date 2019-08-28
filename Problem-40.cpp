//Problem - 40
// https://leetcode.com/problems/combination-sum-ii/submissions/

// Time complextiy exponential O(2^n)

class Solution {
public:
    void fun(vector <vector<int>> &ans, vector <int> v, vector <int> temp, int sum, int ind) {
    if(sum < 0)
        return;
    if(sum == 0) {
        ans.push_back(temp);
        return;
    }
    for(int i = ind; i < v.size(); i++) {
        if(i > ind && v[i] == v[i-1])
            continue;
        temp.push_back(v[i]);
        fun(ans, v, temp, sum-v[i], i+1);
        temp.pop_back();
    }
}
    
    vector<vector<int>> combinationSum2(vector<int>& v, int sum) {
        sort(v.begin(), v.end());
        vector <vector <int>> ans;
        vector <int> temp;
        fun(ans, v, temp, sum, 0);
        return ans;
    }
};

   