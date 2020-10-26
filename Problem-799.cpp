// Problem - 799

// https://leetcode.com/problems/champagne-tower/

// O(r^2) time complexity and O(r^2) space complexity solution using dp (Pascal's Triangle)

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector < vector<double> > dp(query_row+2, vector <double> (query_row+1, 0));
        dp[0][0] = poured;
        for(int i = 0; i < query_row; i++) {
            for(int j = 0; j <= i; j++) {
                if(dp[i][j] >= 1) {
                    double extra = dp[i][j]-1;
                    dp[i][j] = 1;
                    dp[i+1][j] += extra/2.0;
                    dp[i+1][j+1] += extra/2.0;
                }
            }
        }
        return min(dp[query_row][query_glass], 1.0);
    }
};
