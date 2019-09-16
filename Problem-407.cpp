//Problem - 407
// https://leetcode.com/problems/trapping-rain-water-ii/

// O(nm log(mn)) time complexity solution with O(mn) space

class Solution {
public:
    int corX[4] = {1, 0, -1, 0};
    int corY[4] = {0, 1, 0, -1};
    
    int trapRainWater(vector<vector<int>>& height) {
        if(height.size() < 2 || height[0].size() < 2)
            return 0;
        
        int n = height.size();
        int m = height[0].size();
        priority_queue < pair<int, pair<int, int>>, vector <pair<int, pair<int, int>>>, greater <pair<int, pair<int, int>>> > pq;
        vector <vector <bool>> visited(n, vector <bool> (m,0));
        for(int i = 0; i < n; i++) {
            pq.push({height[i][0], {i, 0}});
            visited[i][0] = 1;
            pq.push({height[i][m-1], {i, m-1}});
            visited[i][m-1] = 1;
        }
        for(int i = 0; i < m; i++) {
            pq.push({height[0][i], {0, i}});
            visited[0][i] = 1;
            pq.push({height[n-1][i], {n-1, i}});
            visited[n-1][i] = 1;
        }
        int water = 0;
        while(!pq.empty()) {
            auto pp = pq.top();
            pq.pop();
            int h = pp.first; 
            for(int i = 0; i < 4; i++) {
                int x = pp.second.first + corX[i];
                int y = pp.second.second + corY[i];
                if(x >= 0 && y >= 0 && x < n && y < m && !visited[x][y]) {
                    visited[x][y] = 1;
                    if(height[x][y] < h)
                        water += h - height[x][y];
                    pq.push({max(h, height[x][y]), {x, y}});
                }
            }
        }
        return water;
    }
};