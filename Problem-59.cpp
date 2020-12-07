// Problem - 59

// https://leetcode.com/problems/spiral-matrix-ii/

// O(n*n) time complexity and O(1) space complexity solution

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector <vector <int>> v(n, vector <int> (n, 0));
        int ctr = 1;
        for(int i = 0; i < n/2; i++) {
            for(int j = i; j < n-i-1; j++) {
                v[i][j] = ctr++;
            }
            for(int j = i; j < n-i-1; j++) {
                v[j][n-i-1] = ctr++;
            }
            for(int j = n-i-1; j > i; j--) {
                v[n-i-1][j] = ctr++;
            }
            for(int j = n-i-1; j > i; j--) {
                v[j][i] = ctr++;
            }
        }
        if(n&1)
            v[n/2][n/2] = ctr;
        return v;
    }
};
