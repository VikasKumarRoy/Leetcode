// Problem - 1309

// https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    string freqAlphabets(string s) {
        int n = s.length();
        string ans;
        for(int i = 0; i < n; i++){
            int num;
            if(i+2 < n && s[i+2] == '#') {
                num = ((s[i] - '0') * 10) + (s[i+1] - '0');  
                i += 2;
            }
            else
                num = s[i] - '0';
            ans += 'a' + num - 1;
        }
        return ans;
    }
};