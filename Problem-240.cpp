// Problem - 240

// https://leetcode.com/problems/search-a-2d-matrix-ii/

// O(n + m) time complexity and O(1) space complexity solution

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int r = 0, c = m-1;
        while(r < n && c >= 0) {
            if(matrix[r][c] == target)
                return 1;
            else if(matrix[r][c] > target)
                c--;
            else
                r++;
        }
        return 0;
    }
};