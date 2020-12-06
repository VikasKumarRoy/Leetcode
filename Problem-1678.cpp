// Problem - 1678

// https://leetcode.com/problems/goal-parser-interpretation/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    string interpret(string command) {
        string ans;
        char prev;
        for(char c : command) {
            if(c == 'G')
                ans += 'G';
            else if(c == ')') {
                ans += prev == '(' ? "o" : "al";
            }
            prev = c;
        }
        return ans;
    }
};
