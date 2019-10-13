//Problem - 1221
// https://leetcode.com/problems/split-a-string-in-balanced-strings/

// O(n) time complexity and O(1) space complexity

class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0, ctr = 0;
        for(char c : s) {
            ctr += c == 'L' ? -1 : 1;
            if(!ctr)
                ans++;
        }
        return ans;
    }
};