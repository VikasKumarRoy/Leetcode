//Problem - 812
// https://leetcode.com/problems/largest-triangle-area/

// O(n^3) time complexity and O(1) space complexity sol

class Solution {
public:
    double getArea(pair <int, int> a, pair <int, int> b, pair <int, int> c) {
        return 0.5 * abs(a.first*(b.second-c.second)+b.first*(c.second - a.second)+c.first*(a.second-b.second));
    }
    
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        for(int i = 0; i < points.size()-2; i++)
            for(int j = i + 1; j < points.size()-1; j++)
                for(int k = j + 1; k < points.size(); k++)
                    ans = max(ans, getArea({points[i][0], points[i][1]}, {points[j][0], points[j][1]}, {points[k][0], points[k][1]}));
        
        return ans;
    }
};