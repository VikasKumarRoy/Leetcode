// Problem - 498

// https://leetcode.com/problems/diagonal-traverse/

// O(n*m) time complexity and O(1) space complexity solution

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0)
            return {};
        int m = matrix[0].size();
        vector <int> ans;
        bool up = true;
        int i = 0, j = 0;
        while(ans.size() < n*m) {
            if(up) {
                while(i >= 0 && j < m) {
                    ans.push_back(matrix[i][j]);
                    i--, j++;
                }
                i++, j--;
                if(j < m-1)
                    j++;
                else
                    i++;
            }
            else {
                while(i < n && j >= 0) {
                    ans.push_back(matrix[i][j]);
                    i++, j--;
                }
                i--, j++;
                if(i < n-1)
                    i++;
                else
                    j++;
            }
            up = !up;
        }
        return ans;
    }
};
