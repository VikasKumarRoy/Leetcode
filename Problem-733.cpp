// Problem - 733

// https://leetcode.com/problems/flood-fill/

// O(n*m) time complexity and O(n*m) space complexity solution BFS

class Solution {
private: 
    int dirX[4] = {1, 0, -1, 0};
    int dirY[4] = {0, -1, 0, 1};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) 
            return image;
        int prevColor = image[sr][sc];
        queue <pair<int, int>> q;
        image[sr][sc] = newColor;
        q.push({sr, sc});
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int x = p.first + dirX[i];
                int y = p.second + dirY[i];
                if(x < image.size() && x >= 0 && y < image[0].size() && y >= 0 && image[x][y] == prevColor) {
                    image[x][y] = newColor;
                    q.push({x, y});
                }
            }
        }
        return image;
    }
};
