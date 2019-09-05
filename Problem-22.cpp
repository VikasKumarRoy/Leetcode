//Problem - 22
// https://leetcode.com/problems/generate-parentheses/

// Time Complexity O(n)

class Solution {
public:
    vector <string> ans;
    void printParenthesis(int o, int c, string str) {
        if(o > c)
            return;
        if(o == 0 && c == 0)
            ans.push_back(str);
        if(o > 0)
            printParenthesis(o-1, c, str+"(");
        if(c > 0)
            printParenthesis(o, c-1, str+")");
    }
    
    vector<string> generateParenthesis(int n) {
        if(n > 0)
            printParenthesis(n, n, "");
        return ans;
    }
};