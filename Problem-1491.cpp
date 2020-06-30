// Problem - 1491

// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    double average(vector<int>& salary) {
        int mx = INT_MIN, mn = INT_MAX;
        double sum = 0;
        for(int val : salary) {
            sum += val;
            mx = max(mx, val);
            mn = min(mn, val);
        }
        return (sum-mx-mn)/(salary.size()-2);
    }
};
