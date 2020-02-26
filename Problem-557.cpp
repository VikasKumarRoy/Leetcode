// Problem - 557

// https://leetcode.com/problems/reverse-words-in-a-string-iii/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string ans;
        while(ss >> word) {
            reverse(word.begin(), word.end());
            ans += word + " ";
        }
        ans.pop_back();
        return ans;
    }
};