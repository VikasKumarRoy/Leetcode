// Problem - 856

// https://leetcode.com/problems/score-of-parentheses/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    int scoreOfParentheses(string S) {
        stack <int> st;
        int n = S.length();
        st.push(0);
        for(char c: S) {
            if(c == '(') {
                st.push(0);
            }
            else {
                int val = st.top();
                st.pop();
                int x = 0;
                if(val > 0)
                    x = val*2;
                else
                    x = 1;
                st.top() += x;
            }
        }
        return st.top();
    }
};

