// Problem - 1758

// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int ctr = 0;
        for(int i = 0; i < n; i++) {
            ctr += i&1 ? s[i] == '0' : s[i] == '1';
        }
        return min(ctr, n-ctr);
    }
};
