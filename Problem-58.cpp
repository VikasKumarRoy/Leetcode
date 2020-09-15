// Problem - 58

// https://leetcode.com/problems/length-of-last-word/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int i = s.length()-1;
        while(i >= 0 && s[i] == ' ')
            i--;
        for(; i >= 0; i--) {
            if(s[i] == ' ')
                break;
            ans++;
        }
        return ans;
    }
};
