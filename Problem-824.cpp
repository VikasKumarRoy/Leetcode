// Problem - 824

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    string toGoatLatin(string S) {
        unordered_set <char> vowel = {'a', 'e', 'i', 'o', 'u'};
        string ans, word;
        stringstream ss(S);
        int i = 1;
        while(ss >> word) {
            if(vowel.count(tolower(word[0]))) {
                word += "ma";
            }
            else {
                word = word.substr(1) + word[0] + "ma";
            }
            word += string (i++, 'a') + ' ';
            ans += word;
        }
        return ans.substr(0, ans.length()-1);
    }
};
