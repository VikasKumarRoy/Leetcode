// Problem - 54

// https://leetcode.com/problems/spiral-matrix/

// O(n*m) time complexity and O(1) space complexity solution

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        int n = matrix.size(),m = matrix[0].size();
        int rowStart = 0, rowEnd = n-1;
        int colStart = 0, colEnd = m-1;
        while(1) {
            for(int i = colStart; i <= colEnd; i++) {
                ans.push_back(matrix[rowStart][i]);
            }
            if(ans.size() == n*m)
                break;
            for(int i = rowStart+1; i <= rowEnd; i++) {
                ans.push_back(matrix[i][colEnd]);
            }
            if(ans.size() == n*m)
                break;
            for(int i = colEnd-1; i >= colStart; i--) {
                ans.push_back(matrix[rowEnd][i]);
            }
            if(ans.size() == n*m)
                break;
            for(int i = rowEnd-1; i > rowStart; i--) {
                ans.push_back(matrix[i][colStart]);
            }
            if(ans.size() == n*m)
                break;
            rowStart++, rowEnd--, colStart++, colEnd--;
        }
        return ans;
    }
};
