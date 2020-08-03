// Problem - 520

// https://leetcode.com/problems/detect-capital/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length() < 2)
            return true;
        for(int i = 0; i < word.size(); i++) {
            if(isupper(word[i]) != isupper(word[1])) {
                if((i == 0 && !isupper(word[i])) || i > 1)
                    return false;
            }
        }
        return true;
    }
};
