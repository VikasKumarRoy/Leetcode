// Problem - 1380

// https://leetcode.com/problems/lucky-numbers-in-a-matrix/

// O(n*m) time complexity and O(min(n,m)) space complexity solution

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector <int> ans;
        unordered_set <int> us;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++) {
            int mn = matrix[i][0];
            for(int j = 1; j < m; j++)
                mn = min(mn, matrix[i][j]);
            us.insert(mn);
        }
        for(int i = 0; i < m; i++) {
            int mx = matrix[0][i];
            for(int j = 0; j < n; j++) 
                mx = max(mx, matrix[j][i]);
            if(us.count(mx))
                ans.push_back(mx);
        }
        return ans;
    }
};

