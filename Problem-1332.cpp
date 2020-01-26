// Problem - 1332

// https://leetcode.com/problems/remove-palindromic-subsequences/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.empty())
            return 0;
        else if(s == string(s.rbegin(), s.rend()))
            return 1;
        return 2;
    }
};