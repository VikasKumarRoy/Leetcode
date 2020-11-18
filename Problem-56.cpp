// Problem - 56

// https://leetcode.com/problems/merge-intervals/

// O(nlogn) time complexity and O(1) space complexity solution

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector <vector <int>> ans;
        int st = intervals[0][0], end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(end < intervals[i][0]) {
                ans.push_back({st, end});
                st = intervals[i][0];
            }
            end = max(intervals[i][1], end);
        }
        ans.push_back({st, end});
        return ans;
    }
};
