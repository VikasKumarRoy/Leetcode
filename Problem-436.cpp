// Problem - 436

// https://leetcode.com/problems/find-right-interval/

// O(nlogn) time complexity and O(n) space complexity solution using binary search

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector <int> ans, v;
        unordered_map <int, int> um;
        for(int i = 0; i < intervals.size(); i++) {
            v.push_back(intervals[i][0]);
            um[intervals[i][0]] = i;
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < intervals.size(); i++) {
            int end = intervals[i][1];
            int pos = lower_bound(v.begin(), v.end(), end) - v.begin();
            if(pos >= intervals.size())
                ans.push_back(-1);
            else {
                ans.push_back(um[v[pos]]);
            }
        }
        return ans;
    }
};
