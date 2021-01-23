// Problem - 1329

// https://leetcode.com/problems/sort-the-matrix-diagonally/

// O(nmlog(m)) time complexity and O(nm) space complexity solution

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for(int i = n-1; i >= 0; i--) {
            vector <int> v;
            int k = i;
            for(int j = 0; j < m; j++) {
                v.push_back(mat[k][j]);
                k++;
                if(k >= n)
                    break;
            }
            sort(v.begin(), v.end());
            k = i;
            for(int j = 0; j < m; j++) {
                mat[k][j] = v[j];
                k++;
                if(k >= n)
                    break;
            }
        }
        for(int i = 1; i < m; i++) {
            vector <int> v;
            int k = i;
            for(int j = 0; j < n; j++) {
                v.push_back(mat[j][k]);
                k++;
                if(k >= m)
                    break;
            }
            sort(v.begin(), v.end());
            k = i;
            for(int j = 0; j < n; j++) {
                mat[j][k] = v[j];
                k++;
                if(k >= m)
                    break;
            }
        }
        return mat;
    }
};
