// Problem - 542

// https://leetcode.com/problems/01-matrix/

// O(n*m) time complexity and O(n*m) space complexity solution

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0)
            return {};
        int m = matrix[0].size();
        int MAX = n * m - 1; 
        vector <vector <int>> ans(n, vector <int> (m, MAX));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0)
                    ans[i][j] = 0;
                else {
                    int left = j == 0 ? MAX : ans[i][j-1];
                    int up = i == 0 ? MAX : ans[i-1][j];
                    ans[i][j] = min(up, left) + 1;
                }
            }
        }
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                if(matrix[i][j] == 0)
                    ans[i][j] = 0;
                else {
                    int right = j == m-1 ? MAX : ans[i][j+1];
                    int down = i == n-1 ? MAX : ans[i+1][j];
                    ans[i][j] = min(ans[i][j], min(right, down) + 1);
                }
            }
        }
        return ans;
    }
};
