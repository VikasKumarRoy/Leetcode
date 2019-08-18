//Problem  - 1162
// https://leetcode.com/problems/as-far-from-land-as-possible/

// O(n * m) solution usign bfs
class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
        
    int maxDistance(vector<vector<int>>& grid) {
        queue <pair <int, int> > q;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[i].size(); j++) 
                if(grid[i][j] == 1)
                    q.push({i, j});
        
        int ans = -1;
     
        while(!q.empty()) {
            int u = q.front().first, v = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int x = u + dx[i];
                int y = v + dy[i];
                if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 0) {
                    q.push({x, y});
                    grid[x][y] = grid[u][v] + 1;
                }
            }
        }
        for(int i = 0; i < grid.size(); i++)
            ans = max(ans, *max_element(grid[i].begin(), grid[i].end()));
        
        return ans == 1 ? -1 : ans-1;    
    }
};