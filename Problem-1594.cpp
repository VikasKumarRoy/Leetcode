// Problem - 1594

// https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/

// O(n*m) time complexity and O(n*m) space complexity solution using dp

class Solution {
public:
    int mod = 1e9+7;
    
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector <vector <long long>> dpMx(n, vector <long long> (m, 0));
        dpMx[0][0] = grid[0][0];
        for(int i = 1; i < n; i++) {
            dpMx[i][0] = (grid[i][0] * dpMx[i-1][0]);
        }
        for(int i = 1; i < m; i++) {
            dpMx[0][i] = (grid[0][i] * dpMx[0][i-1]);
        }
        vector <vector <long long>> dpMn = dpMx;
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(grid[i][j] >= 0) {
                    dpMn[i][j] = min(dpMn[i-1][j]*grid[i][j], dpMn[i][j-1]*grid[i][j]);
                    dpMx[i][j] = max(dpMx[i-1][j]*grid[i][j], dpMx[i][j-1]*grid[i][j]);
                }
                else {
                    dpMn[i][j] = min(dpMx[i-1][j]*grid[i][j], dpMx[i][j-1]*grid[i][j]);
                    dpMx[i][j] = max(dpMn[i-1][j]*grid[i][j], dpMn[i][j-1]*grid[i][j]);
                }
            }
        }
        return dpMx[n-1][m-1] < 0 ? -1 : dpMx[n-1][m-1]%mod;
    }
};
