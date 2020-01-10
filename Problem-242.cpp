// Problem - 242

// https://leetcode.com/problems/rotate-array/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector <int> freq(26, 0);
        for(char c : s) 
            freq[c - 'a']++;
        for(char c : t)
            freq[c - 'a']--;
        for(int val : freq)
            if(val != 0)
                return 0;
        return 1;
    }
};