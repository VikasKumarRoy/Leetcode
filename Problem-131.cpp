//Problem  - 131
// https://leetcode.com/problems/palindrome-partitioning/

// Passes all test cases O(2^n)  

class Solution {
public:
    
    bool isPalindrom(string s) {
        int i = 0, n = s.length()-1;
        while(i < n) {
            if(s[i++] != s[n--])
                return false;
        }
        return true;
    }
    
    void fun(vector <vector <string> > &ans, string s, int ind, vector <string> v) {
        if(ind == s.length()) {
            ans.push_back(v);
            return;
        }
        int ctr = 1;
        for(int i = ind; i < s.length(); i++) {
            string str = s.substr(ind, ctr++);
            if(isPalindrom(str)) {
                v.push_back(str);
                fun(ans, s, i+1, v);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector <vector <string>> ans;
        if(s.length() == 0)
            return ans;
        vector <string> v;
        fun(ans, s, 0, v);
        return ans;
    }
};