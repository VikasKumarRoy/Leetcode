// Problem - 1610

// https://leetcode.com/problems/maximum-number-of-visible-points/

// O(nlogn) time complexity and O(n) space complexity solution using sliding window

class Solution {
public:
    double PI = 3.14159265;
    
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int ans = 0, ctr = 0;
        int n = points.size();
        vector <double> angleList;
        int x = location[0], y = location[1];
        for(auto p : points) {
            if(p == location)
                ctr++;
            else {
                double angle_in_degree = atan2 ((p[1] - y), (p[0] - x)) * 180 / PI;
                angleList.push_back(angle_in_degree);
            }
        }
        sort(angleList.begin(), angleList.end());
        vector <double> v = angleList;
        v.insert(v.end(), angleList.begin(), angleList.end());
        for(int i = angleList.size(); i < v.size(); i++)
            v[i] += 360;
        int i = 0, j = 0;
        while(j < v.size()) {
            if(v[j] - v[i] <= angle) {
                j++;
            }
            else
                i++;
            ans = max(ans, j-i);
        }
        return ans + ctr;
    }
};
