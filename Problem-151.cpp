// Problem - 151

// https://leetcode.com/problems/reverse-words-in-a-string/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    string reverseWords(string s) {
        if (!s.length())
            return "";
        stringstream ss(s);
        string word, ans;
        while(ss >> word)
            ans = word + " " + ans;
        return ans.substr(0,ans.length()-1);
    }
};
