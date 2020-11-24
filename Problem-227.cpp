// Problem - 227

// https://leetcode.com/problems/basic-calculator-ii/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    int calculate(string s) {
        stack <int> st;
        int num = 0, ans = 0;
        char prevSign = '+';
        for(int i = 0; i < s.length(); i++) {
            if(isdigit(s[i])) {
                num = num*10 + (s[i]-'0');
            }
            if(i == s.length()-1 || (!isdigit(s[i]) && s[i] != ' ')) {
                if(prevSign == '+') {
                    st.push(num);
                }
                else if(prevSign == '-') {
                    st.push(-num);
                }
                else if(prevSign == '*') {
                    int tp = st.top();
                    st.pop();
                    st.push(tp * num);
                }
                else {
                    int tp = st.top();
                    st.pop();
                    st.push(tp / num);
                }
                num = 0;
                prevSign = s[i];
            }
        }
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
