// Problem - 289

// https://leetcode.com/problems/game-of-life/

// O(n*m) time complexity and O(1) space complexity solution

class Solution {
public:
    int corX[8] = {1, 0, -1, 0, 1, -1, 1, -1};
    int corY[8] = {0, 1, 0, -1, 1, -1, -1, 1};
    
    bool isValid(vector<vector<int>>& board, int i, int j) {
        int n = board.size();
        int m = board[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m)
            return false;
        return true;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int live = 0;
                for(int k = 0; k < 8; k++) {
                    int x = i + corX[k];
                    int y = j + corY[k];
                    if(isValid(board, x, y) && board[x][y] > 0) {
                        live++;
                    }
                }
                if(board[i][j] <= 0) {
                    if(live == 3)
                        board[i][j] = -1;
                }
                else {
                    if(live < 2 || live > 3) {
                        board[i][j] = 2;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == -1)
                    board[i][j] = 1;
                if(board[i][j] == 2)
                    board[i][j] = 0;
            }
        }
    }
};
