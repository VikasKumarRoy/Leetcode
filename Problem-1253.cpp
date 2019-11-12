//Problem - 1253

// https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/

// O(n)  time complexity and O(n) space complexity sol

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int m = colsum.size();
        vector <vector<int>> ans(2, vector <int> (m, 0));
        for(int i = 0; i < m; i++) {
            if(colsum[i] == 2) {
                ans[0][i] = ans[1][i] = 1;
                colsum[i] = 0;
                lower--;
                upper--;
            }
        }
        for(int i = 0; i < m; i++) {
            if(colsum[i] > 0 && upper > 0) {
                colsum[i]--;
                upper--;
                ans[0][i] = 1;
            }
            else if(colsum[i] > 0 && lower > 0) {
                colsum[i]--;
                lower--;
                ans[1][i] = 1;
            }
        }
        if(lower != 0 || upper != 0 || accumulate(colsum.begin(), colsum.end(), 0) != 0)
            ans.clear();
        return ans;
    }
};
