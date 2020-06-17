// Problem - 130

// https://leetcode.com/problems/surrounded-regions/

// O(n*m) time complexity and O(1) space complexity solution using dfs

class Solution {
public:
    int n, m;
    int corX[4] = {1, -1, 0, 0};
    int corY[4] = {0, 0, 1, -1};
    
    void dfs(vector<vector<char>>& board, int i, int j) {
        if(i >= n || i < 0 || j >= m || j < 0 || board[i][j] != 'O')
            return;
        board[i][j] = 'Y';
        for(int k = 0; k < 4; k++) {
            dfs(board, i+corX[k], j+corY[k]);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return;
        n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O')
                dfs(board, i, 0);
            if(board[i][m-1] == 'O')
                dfs(board, i, m-1);
        }
        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O')
                dfs(board, 0, j);
            if(board[n-1][j] == 'O')
                dfs(board, n-1, j);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == 'Y')
                    board[i][j] = 'O';
            }
        }
    }
};
