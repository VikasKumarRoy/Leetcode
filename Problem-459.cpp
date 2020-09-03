// Problem - 459

// https://leetcode.com/problems/repeated-substring-pattern/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str = s + s;
        return str.substr(1, s.length() * 2 - 2).find(s) != -1;
    }
};
