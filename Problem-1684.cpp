// Problem - 1684

// https://leetcode.com/problems/count-the-number-of-consistent-strings/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        unordered_set <char> us;
        for(char c : allowed)
            us.insert(c);
        for(string s : words) {
            bool allowed = true;
            for(char c : s) {
                if(!us.count(c)) {
                    allowed = false;
                    break;
                }
            }
            if(allowed)
                ans++;
        }
        return ans;
    }
};
