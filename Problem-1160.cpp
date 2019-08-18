//Problem  - 1160
// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/


// O(n) solution with O(1) space
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector <int> freq(26);
        for(char c : chars)
            freq[c - 'a']++;
        int ans = 0;
        for(int i = 0; i < words.size(); i++) {
            vector <int> temp = freq;
            bool flag = 1;
            for(char c : words[i]) {
                temp[c - 'a']--;
                if(temp[c - 'a'] < 0) {
                    flag = 0;
                    break;
                } 
            }
            if(flag)
                ans += words[i].length();
        }
        return ans;
    }
};