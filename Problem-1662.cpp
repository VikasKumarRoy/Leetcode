// Problem - 1662

// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1, str2;
        for(string s : word1)
            str1 += s;
        for(string s : word2)
            str2 += s;
        return str1 == str2;
    }
};
