// Problem - 497

// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/

// O(nlogn) time complexity and O(n) space complexity solution using area as weights for ramdom pick

class Solution {
public:
    vector <vector <int>> rect;
    map <int, int> m;
    int totalArea = 0;
    
    Solution(vector<vector<int>>& rects) {
        rect = rects;
        totalArea = 0;
        for(int i = 0; i < rect.size(); i++) {
            totalArea += (rect[i][2] - rect[i][0] + 1) * (rect[i][3] - rect[i][1] + 1);
            m[totalArea] = i;
        }
    }
    
    vector<int> pick() {
        int r = rand() % totalArea;
        auto it = m.upper_bound(r);
        int ind = it->second;
        int x = rand() % (rect[ind][2] - rect[ind][0] + 1) + rect[ind][0];
        int y = rand() % (rect[ind][3] - rect[ind][1] + 1) + rect[ind][1];
        return {x, y};
    }
};
