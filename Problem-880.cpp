// Problem - 880

// https://leetcode.com/problems/decoded-string-at-index/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        string str;
        long len = 0;
        for(char c : S) {
            if(isdigit(c))
                len *= c - '0';
            else
                len++;
        }
        for(int i = S.length()-1; i >= 0; i--) {
            K %= len;
            if(K == 0 && isalpha(S[i]))
                return string(1, S[i]);
            if(isdigit(S[i]))
                len /= S[i] - '0';
            else
                len--;
        }
        return "";
    }
};
