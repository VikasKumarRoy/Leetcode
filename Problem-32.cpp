//Problem - 32
// https://leetcode.com/problems/longest-valid-parentheses/

// O(n) solution using stack

class Solution {
public:
    int longestValidParentheses(string s) {
        stack <int> st;
        int ans = 0;
        st.push(-1);
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(')
                st.push(i);
            else {
                st.pop();
                if(!st.empty()) {
                    ans = max(ans, i - st.top());
                }
                else st.push(i);
            }
        }
        return ans;
    }
};

// O(n) solution using dp

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() < 2)
            return 0;
        vector <int> dp(s.length());
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == ')') {
                if(i-2 >= 0 && s[i-1] == '(')
                    dp[i] = dp[i-2] + 2;
                else {
                    if(i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(')
                        dp[i] = dp[i-1] + 2 + (i-dp[i-1]-2 >=0 ? dp[i-dp[i-1]-2] : 0);
                }
            }
                
        }
        return *max_element(dp.begin(), dp.end());
    }
};

   