// Problem - 1672

// https://leetcode.com/problems/richest-customer-wealth/

// O(n*m) time complexity and O(1) space complexity solution

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for(auto v : accounts) {
            ans = max(ans, accumulate(v.begin(), v.end(), 0));
        }
        return ans;
    }
};
