// Problem - 567

// https://leetcode.com/problems/permutation-in-string/

// O(n+m) time complexity and O(m) space complexity solution using sliding window

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector <int> freq(26, 0);
        for(char c : s1)
            freq[c-'a']++;
        int i = 0, j =0;
        int len = 0, n = s1.length();
        while(j < s2.length()) {
            if(freq[s2[j]-'a']) {
                len++;
                freq[s2[j]-'a']--;
                j++;
            }
            else {
                if(i == j) {
                    i++, j++;
                }
                else {
                    freq[s2[i]-'a']++;
                    i++;
                    len--;
                }
            }
            if(len == n)
                return true;
        }
        return false;
    }
};
