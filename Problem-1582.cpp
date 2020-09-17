// Problem - 1582

// https://leetcode.com/problems/special-positions-in-a-binary-matrix/

// O(n*m) time complexity and O(n + m) space complexity solution

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector <int> row(n), col(m);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    if(row[i] == 1 && col[j] == 1)
                        ans++;
                }
            }
        }
        return ans;
    }
};
