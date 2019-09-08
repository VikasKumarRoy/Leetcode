//Problem - 20
// https://leetcode.com/problems/valid-parentheses/

// O(n) time complexity with O(n) space 

class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(char c : s) {
            if(c == '(' || c == '{' || c == '[')
                st.push(c);
            else {
                if(st.empty())
                    return false;
                if(c == ')' && st.top() != '(') return false;
                if(c == ']' && st.top() != '[') return false;
                if(c == '}' && st.top() != '{') return false;
                st.pop();
            }
        }
        return st.empty() ? 1 : 0;
    }
};