// Problem - 1030

// https://leetcode.com/problems/matrix-cells-in-distance-order/

// O(n*m) time complexity and O(n*m) space complexity solution using bfs

class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector <vector <int>> visited(R, vector <int> (C, 0));
        vector <vector <int>> ans;
        queue <pair <int, int>> q;
        q.push({r0, c0});
        visited[r0][c0] = 1;
        while(!q.empty()) {
          auto p = q.front();
          q.pop();
          ans.push_back({p.first, p.second});
          for(int i = 0; i < 4; i++) {
              int x = p.first + dx[i];
              int y = p.second + dy[i];
              if(x >= 0 && y >= 0 && x < R && y < C && !visited[x][y]) {
                  visited[x][y] = 1;
                  q.push({x, y});
              }
          }
        }
        return ans;
    }
};