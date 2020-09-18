// Problem - 1572

// https://leetcode.com/problems/matrix-diagonal-sum/

// O(n^2) time complexity and O(1) space complexity solution

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += mat[i][i];
        }
        for(int i = 0; i < n/2; i++) {
            ans += mat[i][n-i-1] + mat[n-i-1][i];
        }
        return ans;
    }
};
