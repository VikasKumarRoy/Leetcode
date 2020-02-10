// Problem - 1347

// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int minSteps(string s, string t) {
        vector <int> alpha(26, 0);
        for(int i = 0; i < s.length(); i++)
            alpha[s[i] - 'a']++, alpha[t[i] - 'a']--;
        int sum = 0;
        for(int i = 0; i < 26; i++)
            sum += abs(alpha[i]);
        return sum/2;
    }
};