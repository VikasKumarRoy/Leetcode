// Problem - 409

// https://leetcode.com/problems/longest-palindrome/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map <char, int> um;
        int ans = 0;
        bool flag = 0;
        for(char c : s)
            um[c]++;
        for(auto it : um) {
            if(it.second & 1) {
                flag = 1;
                ans += it.second - 1;
            }
            else
                ans += it.second;
        }
        if(flag)
            ans++;
        return ans;
    }
};
