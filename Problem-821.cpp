// Problem - 821

// https://leetcode.com/problems/shortest-distance-to-a-character/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector <int> ans(n, n);
        int d = n;
        for(int i = 0; i < n; i++) {
            d = s[i] == c ? 0 : d+1;
            ans[i] = min(ans[i], d);
        }
        d = n;
        for(int i = n-1; i >= 0; i--) {
            d = s[i] == c ? 0 : d+1;
            ans[i] = min(ans[i], d);
        }
        return ans;
    }
};
