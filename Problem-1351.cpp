// Problem - 1351

// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

// O(n + m) time complexity and O(1) space complexity solution

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int r = 0, c = m-1, ans = 0;
        while(r < n && c >= 0) {
            if(grid[r][c] < 0) {
                ans += n - r;
                c--;
            }
            else
                r++;
        }
        return ans;
    }
};