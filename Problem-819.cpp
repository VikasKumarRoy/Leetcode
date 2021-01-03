// Problem - 819

// https://leetcode.com/problems/most-common-word/

// O(n+m) time complexity and O(n+m) space complexity solution
// where n = no. of chars in paragraph and m = no. of chars in banned list

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string ans;
        int mx = 0;
        unordered_set <string> us(banned.begin(), banned.end());
        unordered_map <string, int> um;
        for(char &c : paragraph) {
            c = isalpha(c) ? tolower(c) : ' ';
        }
        stringstream ss(paragraph);
        string word;
        while(ss >> word) {
            if(!us.count(word)) {
                um[word]++;
                if(um[word] > um[ans]) {
                    ans = word;
                }
            }
        }
        return ans;
    }
};
