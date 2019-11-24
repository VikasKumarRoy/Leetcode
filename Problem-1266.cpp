//Problem - 1266

// https://leetcode.com/problems/minimum-time-visiting-all-points/

// O(n) time complexity and O(1) space complexity sol

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        if(points.size() < 2)
            return 0;
        int ans = 0;
        for(int i = 0; i < points.size()-1; i++) {
            int d1 = abs(points[i][0] - points[i+1][0]);
            int d2 = abs(points[i][1] - points[i+1][1]);
            ans += max(d1, d2);
        }
        return ans;
    }
};