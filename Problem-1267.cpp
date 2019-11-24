//Problem - 1267

// https://leetcode.com/problems/count-servers-that-communicate/

// O(n*m) time complexity and O(n*m) space complexity sol

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        if(i >= n || j >= m)
            return 0;
        grid[i][j] = 0;
        int s = 0;
        for(int k = 0; k < n; k++) {
            if(grid[k][j] == 1)
                s += dfs(grid, k, j);
        }
        for(int k = 0; k < m; k++) {
            if(grid[i][k] == 1)
                s += dfs(grid, i, k);
        }
        return 1 + s;
    }
    
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j]) {
                    int t = dfs(grid, i, j);
                    if(t > 1)
                        ans += t;
                }
            }
        }
        return ans;
    }
};