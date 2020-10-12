// Problem - 452

// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

// O(nlogn) time complexity and O(1) space complexity solution

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0)
            return 0;
        sort(points.begin(), points.end());
        int ans = 1;
        int end = points[0][1];
        for(int i = 1; i < points.size(); i++) {
            while(i < points.size() && end >= points[i][0]) {
                end = min(end, points[i][1]);
                i++;
            }
            if(i < points.size()) {
                ans++;
                end = points[i][1];
            }
        }
        return ans;
    }
};
