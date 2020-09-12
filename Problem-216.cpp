// Problem - 216

// https://leetcode.com/problems/combination-sum-iii/

// O(C(9,k)) time complexity and O(k) space complexity solution using backtracking

class Solution {
public:
    vector <vector<int>> ans; 
    
    void dfs(vector <int> &temp, int k, int n) {
        if(n < 0)
            return;
        if(temp.size() == k) {
            if(n == 0)
                ans.push_back(temp);
            return;
        }
        int sz = temp.size();
        for(int i = sz ? temp[sz-1]+1 : 1; i < 10; i++) {
            temp.push_back(i);
            dfs(temp, k, n-i);
            temp.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector <int> temp;
        dfs(temp, k, n);
        return ans;
    }
};
