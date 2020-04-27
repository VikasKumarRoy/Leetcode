// Problem - 1422

// https://leetcode.com/problems/maximum-score-after-splitting-a-string/

// O(n) time complexity and O(1) space complexity

class Solution {
public:
    int maxScore(string s) {
        int count = 0;
        for(char c : s)
            count += (c == '1');
        int n = s.length();
        int curr = 0, ans = 0;
        for(int i = 0; i < n-1; i++) {
            curr += (s[i] == '1');
            ans = max(ans, (i+1-curr)+(count-curr) );
        }
        return ans;
    }
};
