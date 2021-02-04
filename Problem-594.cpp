// Problem - 594

// https://leetcode.com/problems/longest-harmonious-subsequence/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map <int, int> um;
        int mx = 0;
        for(int val: nums) {
            um[val]++;
            if(um.count(val+1))
                mx = max(mx, um[val] + um[val+1]);
            if(um.count(val-1))
                mx = max(mx, um[val] + um[val-1]);
        }
        return mx;
    }
};
