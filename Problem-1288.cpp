// Problem - 1288

// https://leetcode.com/problems/remove-covered-intervals/

// O(nlogn) time complexity and O(1) space complexity solution

class Solution {
public:
    static bool mycomp(vector <int> &v1, vector <int> &v2) {
        if(v1[0] == v2[0])
            return v1[1] > v2[1];
        else
            return v1[0] < v2[0];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), mycomp);
        int mx = intervals[0][1];
        int ans = 0;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][1] <= mx)
                ans++;
            mx = max(mx, intervals[i][1]);
        }
        return intervals.size()-ans;
    }
};
