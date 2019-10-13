//Problem - 1222
// https://leetcode.com/problems/queens-that-can-attack-the-king/

// O(n) time complexity and O(1) space complexity

class Solution {
public:
    int corX[8] = {1, 1, -1, -1, 0, 0, 1, -1};
    int corY[8] = {0, -1, 1, 0, 1, -1, 1, -1};
    
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector <vector <int>> ans;
        vector <vector <int>> grid(8, vector <int> (8, 0));
        
        for(int i = 0; i < queens.size(); i++)
            grid[queens[i][0]][queens[i][1]] = 1;
        
        for(int i = 0; i < 8; i++) {
            int x = king[0];
            int y = king[1];
            while(1) {
                x += corX[i];
                y += corY[i];
                if(x >= 8 || y >= 8 || x < 0 || y < 0)
                    break;
                if(grid[x][y] == 1) {
                    ans.push_back({x, y});
                    break;
                }
            }
        }
        return ans;
    }
};