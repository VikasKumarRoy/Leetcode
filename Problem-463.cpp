//Problem - 463

// https://leetcode.com/problems/island-perimeter/

// O(n*m) time complexity and O(1) space complexity solution

class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j]) {
                    for(int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[i].size() || !grid[x][y])
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};