//Problem - 200
// https://leetcode.com/problems/number-of-islands/

// O(m*n) time complexity and O(m*n) space complexity sol

class Solution {
public:
    int corX[4] = {-1, 1, 0, 0};
    int corY[4] = {0, 0, -1, 1};
    
    bool isValid(vector<vector<char>>& grid, int i, int j) {
        if(i >= grid.size() || i < 0) {
            return false;
        }
        if(j >= grid[i].size() || j < 0) {
            return false;
        }
        return true;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++)    {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '2' || grid[i][j] == '0')
                    continue;
                else {
                    ans++;
                    stack <pair<int, int>> s;
                    s.push({i, j});
                    grid[i][j] = '2';
                    while(!s.empty()) {
                        auto p = s.top();
                        s.pop();
                        
                        for(int k = 0; k < 4; k++) {
                            int x = p.first + corX[k];
                            int y = p.second + corY[k];
                            if(isValid(grid, x, y) && grid[x][y] == '1') {
                                grid[x][y] = '2';
                                s.push({x, y});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};