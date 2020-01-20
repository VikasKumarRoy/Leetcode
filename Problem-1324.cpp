// Problem - 1324

// https://leetcode.com/problems/print-words-vertically/

// O(n*m) time complexity and O(n*m) space complexity solution

class Solution {
public:
    
    string WHITESPACE = " \n\r\t\f\v";
    
    string trim(string& s) {
        auto end = s.find_last_not_of(WHITESPACE);
        return (end == string::npos) ? "" : s.substr(0, end + 1);
    }
    
    vector<string> printVertically(string s) {
        stringstream ss(s);
        string word;
        vector <string> v;
        int maxLen = 0;
        while(ss >> word) {
            maxLen = max((int)word.length(), maxLen);
            v.push_back(word);
        }
        vector <string> ans;
        for(int i = 0; i < maxLen; i++) {
            string str;
            for(int j = 0; j < v.size(); j++) {
                if(i >= v[j].length())
                    str += " ";
                else
                    str += v[j][i];
            }
            ans.push_back(trim(str));
        }
        return ans;
    }
};