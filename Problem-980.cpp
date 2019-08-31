//Problem - 980
// https://leetcode.com/problems/word-ladder/

// O(4 ^ (m * n)) time complexity solution using dfs

class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    pair <int, int> src;
    int n, m, ans = 0;
    
    bool isValid(int x, int y, int n, int m) {
        if(x > n-1 || y > m-1 || x < 0 || y < 0)
            return 0;
        return 1;
    }
    
    void dfs(int a, int b, vector<vector<int>> grid, int todo) {
        todo--;
        if(todo < 0)
            return;
        if(grid[a][b] == 2) {
            if(todo == 0)   ans++;
            return;
        }
        grid[a][b] = 3;
        for(int k = 0; k < 4; k++) {
            int x = a + dx[k];
            int y = b + dy[k];
            if(isValid(x, y, n, m)) {
                if(grid[x][y] == 0 || grid[x][y] == 2)
                    dfs(x, y, grid, todo);
            }
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        int todo = 0;
        n = grid.size();
        m = grid[0].size();
        vector <vector <long>> dp(n, vector <long> (m, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != -1)
                    todo++;
                if(grid[i][j] == 1)
                    src.first = i, src.second = j;
            }
        dfs(src.first, src.second, grid, todo);
        return ans;
    }
};
   