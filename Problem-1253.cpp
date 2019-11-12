//Problem - 1253

// https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/

// O(n)  time complexity and O(n) space complexity sol

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int m = colsum.size();
        int n = 2;
        vector <vector<int>> ans(n, vector <int> (m, 0));
        for(int i = 0; i < m; i++) {
            if(colsum[i] > 0 && upper > 0) {
                colsum[i]--;
                upper--;
                ans[0][i] = 1;
            }
        }
        for(int i = 0; i < m; i++) {
            if(colsum[i] > 0 && lower > 0) {
                colsum[i]--;
                lower--;
                ans[1][i] = 1;
            }
        }
        vector <vector <int>> v;
        if(lower != 0 || upper != 0)
            return v;
        return ans;
    }
};
