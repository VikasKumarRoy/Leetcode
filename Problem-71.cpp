// Problem - 71

// https://leetcode.com/problems/simplify-path/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    string simplifyPath(string path) {
        stack <string> st;
        int i = 0;
        string curr, ans;
        int n = path.length();
        while(i < n) {
            if(path[i] == '/') {
                if(curr == ".." && st.size() > 0) {
                    st.pop();
                }
                else if(curr != "" && curr != "." && curr != "..")
                    st.push(curr);
                curr = "";
                while(i < n && path[i] == '/')
                    i++;
            }
            if(i == n)
                break;
            curr += path[i++];
        }
        if(curr == ".." && st.size() > 0) {
            st.pop();
        }
        else if(curr != "" && curr != "." && curr != "..")
            st.push(curr);
        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans.length() ? ans : "/";
    }
};
