//Problem  - 696
// https://leetcode.com/problems/count-binary-substrings/


// O(n) solution passes all tc

class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, curr = 1;
        int ans = 0;
        
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i-1]) {
                curr++;
            } else {
                ans += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }
        
        ans += min(prev, curr);
        
        return ans;
    }
};