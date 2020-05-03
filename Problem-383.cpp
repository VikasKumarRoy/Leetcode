// Problem - 383

// https://leetcode.com/problems/ransom-note/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    bool canConstruct(string ransom, string mag) {
        vector <int> freq(26);
        for(char c : mag) {
            freq[c-'a']++;
        }
        for(char c : ransom) {
            if(--freq[c-'a'] < 0)
                return 0;
        }
        return 1;
    }
};
