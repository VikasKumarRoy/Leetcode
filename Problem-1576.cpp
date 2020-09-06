// Problem - 1576

// https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    string modifyString(string s) {
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '?') {
                char prev = i > 0 ? s[i-1] : 'Z';
                char next = i < s.length()-1 && s[i+1] != '?' ? s[i+1] : 'Z';
                char c = 'a';
                while(c == prev || c == next) {
                    c++;
                }
                s[i] = c;
            }
        }
        return s;
    }
};
