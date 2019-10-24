//Problem - 9
// https://leetcode.com/problems/palindrome-number/

// O(n) time complexity and O(1) space complexity sol

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        if(s[0] == '-')
            return false;
        string r = s;
        reverse(r.begin(), r.end());
        return s == r;
    }
};