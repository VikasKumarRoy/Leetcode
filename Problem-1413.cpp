// Problem - 1413

// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/

// Time Complexity O(n) and space O(1)

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mn = 0;
        int sum = 0;
        for(int val : nums) {
            sum += val;
            mn = min(mn, sum);
        }
        return abs(mn)+1;
    }
};
