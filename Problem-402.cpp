 
// Problem - 402

// https://leetcode.com/problems/remove-k-digits/

// O(n) time complexity and O(n) space complexity

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if(k == 0)
            return num;
        if(k == n)
            return "0";
        stack <char> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && k > 0 && num[i] < s.top()) {
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(k--) {
            s.pop();
        }
        string ans;
        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }
        cout << ans;
        int i = ans.length()-1;
        while(ans.length() && ans[i--] == '0'){
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans.length() ? ans : "0";
    }
};
