//Problem - 1208
// https://leetcode.com/problems/get-equal-substrings-within-budget/

// Time Complexity O(n) and O(1) space

class Solution {
public:
    
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0, j = 0;
        while(j < s.size()) {
            maxCost -= abs(s[j] - t[j]);
            if(maxCost < 0) {
                maxCost += abs(s[i] - t[i]);
                i++;
            }
            j++;
        }
        return j - i;
    }
};


