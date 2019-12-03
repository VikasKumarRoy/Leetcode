//Problem - 1275

// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/

// O(moves.size()) time complexity and O(1) space complexity

class Solution {
public:
    
    bool isWinner(vector <string> &grid) {
        int ctr = 0, ctr1 = 0;
        for(int i = 0; i < 3; i++) {
            ctr = 0, ctr1 = 0;
            char c1 = grid[i][0], c2 = grid[0][i]; 
            for(int j = 0; j < 3; j++) {
                if(grid[i][j] == c1 && c1 != '$')
                    ctr++;
                if(grid[j][i] == c2 && c2 != '$')
                    ctr1++;
            }
            if(ctr == 3 || ctr1 == 3)
                return 1;
        }
        ctr = ctr1 = 0;
        char c1 = grid[0][0], c2 = grid[2][0];
        for(int i = 0, j = 0; i < 3; i++, j++) {
            if(grid[i][j] == c1 && c1 != '$')
                ctr++;
            if(grid[i][2-j] == c2 && c2 != '$')
                ctr1++;
        }
        if(ctr == 3 || ctr1 == 3)
            return 1;
        return 0;
    }
    
    string tictactoe(vector<vector<int>>& moves) {
        vector <string> grid(3, "$$$");
        int i = 0;
        for(i = 0; i < moves.size(); i++) {
            grid[moves[i][0]][moves[i][1]] = i&1 ? 'B' : 'A';
            if(isWinner(grid))
                return (i&1 ? "B" : "A");
        }
        if(i == 9)
            return "Draw";
        return "Pending";
    }
};