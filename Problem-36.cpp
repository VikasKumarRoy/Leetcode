//Problem - 36
// https://leetcode.com/problems/valid-sudoku/

// O(n^3) time comlexity solution passes all tc

class Solution {
public:
    bool isSafe(int row, int col, vector<vector <char>> board, char c) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] != '.' && board[i][col] == c && i != row)
                return false;
            if(board[row][i] != '.' && board[row][i] == c && i != col)
                return false;
        }
        int st_r = row / 3 * 3;
        int st_c = col / 3 * 3;
        for(int i = st_r; i < st_r + 3; i++) {
            for(int j = st_c; j < st_c + 3; j++) {
                if(i == row && j == col)
                    continue;
                if(board[i][j] == c)
                    return false;
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        bool check = true;
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    check &= isSafe(i, j, board, board[i][j]);
                }
                if(!check) 
                    return false;
            }
        return true;
    }
};
   