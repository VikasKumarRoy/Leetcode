// Problem - 395

// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

// O(n^2) time complexity and O(n) space complexity solution using divide and conquor

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if(k > n)
            return 0;
        vector <int> freq(26, 0);
        for(char c : s) {
            freq[c-'a']++;
        }
        int pv = 0;
        while(pv < n && freq[s[pv]-'a'] >= k) {
            pv++;
        }
        if(pv == n)
            return n;
        int left = longestSubstring(s.substr(0, pv), k);
        int right = longestSubstring(s.substr(pv+1), k);
        return max(left, right);
    }
};
