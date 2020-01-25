// Problem - 869

// https://leetcode.com/problems/transpose-matrix/

// O(n*m) time complexity and O(n*m) space complexity solution

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector <vector<int>> B(m, vector <int> (n, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                B[j][i] = A[i][j];
        return B;
    }
};