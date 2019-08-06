//Problem  - 764
// https://leetcode.com/problems/largest-plus-sign/


// O(n*n) time and space complexity solution passes all test cases
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        if(n == 0)
            return 0;
        int ans = 0;
        vector <vector <int>> grid(n, vector <int> (n, 1));
        for(int i = 0 ; i < mines.size(); i++)
            grid[mines[i][0]][mines[i][1]] = 0;
        vector <vector <int>> left(n, vector <int> (n, 0)), right(n, vector <int> (n, 0)),
        top(n, vector <int> (n, 0)), bottom(n, vector <int> (n, 0));
        top[0] = grid[0];
        bottom[n-1] = grid[n-1];
        for(int i = 0; i < n; i++) {
            left[i][0] = grid[i][0];
            right[i][n-1] = grid[i][n-1];
        }        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) {
                left[i][j] = grid[i][j] ? left[i][j-1] + 1 : 0;
                top[j][i] = grid[j][i] ? top[j-1][i] + 1 : 0;
                int t = n - j - 1;
                right[i][t] = grid[i][t] ? right[i][t+1] + 1 : 0;
                bottom[t][i] = grid[t][i] ? bottom[t+1][i] + 1 : 0;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, min(left[i][j], min(right[i][j], min(top[i][j], bottom[i][j]))));
            }
        }
        return ans;
    }
};
