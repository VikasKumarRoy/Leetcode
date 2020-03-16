// Problem - 1371

// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
 
    int findTheLongestSubstring(string s) {
        int mask = 0, ans = 0;
        unordered_map <int, int> um;
        um[0] = -1;
        string vowel = "aeiou";
        for(int i = 0; i < s.length(); i++) {
            int pos = vowel.find(s[i]);
            if(pos != -1)
                mask ^= 1 << pos;
            if(!um.count(mask))
                um[mask] = i;
            ans = max(ans, i-um[mask]);
        }
        return ans;
    }
};

