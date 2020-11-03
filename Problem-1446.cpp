// Problem - 1446

// https://leetcode.com/problems/consecutive-characters/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int maxPower(string s) {
        char last = 'A';
        int ctr = 1, ans = 0;
        for(char c : s) {
            if(c == last)
                ctr++;
            else {
                ctr = 1;
                last = c;
            }
            ans = max(ans, ctr);
        }
        return ans;
    }
};
