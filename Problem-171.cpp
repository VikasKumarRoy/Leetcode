// Problem - 171

// https://leetcode.com/problems/excel-sheet-column-number/

// O(len) time complexity and O(1) space complexity solution

class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0, n = s.length();
        for(int i = 0; i < n; i++) {
            ans += (s[i] - 'A' + 1) * pow(26, n-i-1);
        }
        return ans;
    }
};
