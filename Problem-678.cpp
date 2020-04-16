// Problem - 678

// https://leetcode.com/problems/valid-parenthesis-string/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    bool checkValidString(string s) {
        int mn = 0, mx = 0;
        for(char c : s) {
            if(c == '(')
                mn++, mx++;
            else if(c == '*')
                mx++, mn = max(0, --mn);
            else {
                mx--; mn = max(0, --mn);
            }
            if(mx < 0)
                return 0;
        }
        return mn == 0;
    }
};
