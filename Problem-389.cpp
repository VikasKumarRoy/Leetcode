// Problem - 389

// https://leetcode.com/problems/find-the-difference/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    char findTheDifference(string s, string t) {
        int xr = 0;
        for(char c : s) {
            xr ^= c - 'a';
        }
        for(char c : t) {
            xr ^= c - 'a';
        }
        return 'a'+xr;
    }
};
