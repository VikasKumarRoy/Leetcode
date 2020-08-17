// Problem - 435

// https://leetcode.com/problems/non-overlapping-intervals/

// O(nlogn) time complexity and O(1) space complexity solution

class Solution {
public:
    static bool mysort(const vector<int> &a, const vector <int> &b) {
        return a[0] < b[0];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(), intervals.end(), mysort);
        int end = INT_MIN;
        for(int i = 0; i < intervals.size(); i++) {
            if(intervals[i][0] < end) {
                ans++;
                end = min(end, intervals[i][1]);
            }
            else {
                end = intervals[i][1];
            }
        }
        return ans;
    }
};
