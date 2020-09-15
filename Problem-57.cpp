// Problem - 57

// https://leetcode.com/problems/insert-interval/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector <vector<int>> ans;
        int i = 0, n = intervals.size();
        int st = newInterval[0], end = newInterval[1];
        int newSt = INT_MAX, newEnd = end;
        while(i < n) {
            int a = intervals[i][0], b = intervals[i][1];
            if(st > b) {
                ans.push_back({a, b});
                i++;
            }
            else {
                newSt = min(a, st);
                break;
            }
        }
        if(newSt != INT_MAX) {
            while(i < n) {
                int a = intervals[i][0], b = intervals[i][1];
                if(end >= a) {
                    newEnd = max(end, b);
                    i++;
                }
                else
                    break;
            }
            ans.push_back({newSt, newEnd});
            while(i < n) {
                ans.push_back(intervals[i++]);
            }
        }
        else {
            ans.push_back({st, end});
        }
        return ans;
    }
};
