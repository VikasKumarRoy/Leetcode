// Problem - 1592

// https://leetcode.com/problems/rearrange-spaces-between-words/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    string reorderSpaces(string text) {
        int spaces = 0, words = 0;
        for(char c : text) {
            if(c == ' ')
                spaces++;
        }
        stringstream ss(text);
        string word;
        while(ss >> word) {
            words++;
        }
        string ans;
        int c = words == 1 ? 0 : spaces/(words-1);
        int d = spaces - ((words-1)*c);
        stringstream ss2(text);
        while(ss2 >> word) {
            ans += word;
            int ctr = c;
            while(ctr--) {
                ans += ' ';
            }
        }
        int i = ans.length()-1;
        while(ans[i] == ' ') {
            ans.erase(ans.begin() + i);
            i--;
        }
        while(d--)
            ans += ' ';
        return ans;
    }
};
