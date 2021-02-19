// Problem - 1249

// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

// O(n) time complexity and O(n) space complexity solution using stack

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set <int> us;
        stack <int> st;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == ')') {
                if(st.empty()) {
                    us.insert(i);
                }
                else {
                    st.pop();
                }
            }
        }
        while(!st.empty()) {
            us.insert(st.top());
            st.pop();
        }
        string ans;
        for(int i = 0; i < s.length(); i++) {
            if(!us.count(i)) {
                ans += s[i];
            }
        }
        return ans;
    }
};
