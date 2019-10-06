//Problem - 1218
// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

// Time Complexity O(n) and O(n) space

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int ans = 0;
        unordered_map <int, int> um;
        for(int i = 0; i < arr.size(); i++) {
            um[arr[i]] = um[arr[i] - diff] + 1;
            ans = max(ans, um[arr[i]]);
        }
        return ans;
    }
};


