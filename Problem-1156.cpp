//Problem  - 1156
// https://leetcode.com/problems/swap-for-longest-repeated-character-substring/


// O(n*n) solution passes all tc

class Solution {
public:
    int maxRepOpt1(string text) {
        if(text.size() < 2)
            return text.size();
        int freq[26] = {0};
        int ans = 0;
        for(auto c : text)
            freq[c - 'a']++;
        int curr = 1;
        int skip = 0;
        for(int i = 0; i < text.length()-1; i++) {
            skip = 0, curr = 1;
            for(int j = i+1; j < text.length(); j++) {
                if((text[j] == text[i] || skip == 0) && curr < freq[text[i] - 'a']) {
                    if(text[j] != text[i])
                        skip++;
                    curr++;
                } else break;
            }
            ans = max(ans, curr);
        }
        
        return ans;
    }
};