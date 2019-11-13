//Problem - 832

// https://leetcode.com/problems/flipping-an-image/

// O(n*m)  time complexity and O(n*m) space complexity sol

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        vector <vector<int>> ans(n, vector <int> (m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans[i][m-j-1] = A[i][j] == 0 ? 1 : 0;
            }
        }
        return ans;
    }
};
