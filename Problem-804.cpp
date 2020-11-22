// Problem - 804

// https://leetcode.com/problems/unique-morse-code-words/

// O(n) time complexity and O(n) space complexity solution where n = sum of lenght of all strings

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector <string> v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set <string> us;
        for(string word : words) {
            string s;
            for(char c : word) {
                s += v[c-'a'];
            }
            us.insert(s);
        }
        return us.size();
    }
};
