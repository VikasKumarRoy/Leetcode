// Problem-844

// https://leetcode.com/problems/backspace-string-compare/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s = "";
        string t = "";
        for(char c : S) {
            if(c == '#') {
                if(!s.empty())
                    s.pop_back();
            }
            else 
                s += c;
        }
        for(char c : T) {
            if(c == '#') {
                if(!t.empty())
                    t.pop_back();
            }
            else 
                t += c;
        }
        return s == t;
    }
};

// O(n) time with constant space

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size()-1, j = T.size()-1;
        while(i >= 0 || j >= 0) {
            int ctr = 0;
            while(i >= 0 && (S[i] == '#' || ctr > 0))
                ctr += S[i--] == '#' ? 1 : -1;
            ctr = 0;
            while(j >= 0 && (T[j] == '#' || ctr > 0))
                ctr += T[j--] == '#' ? 1 : -1;
            if(i >= 0 && j >= 0 && S[i] != T[j]) 
                return 0;
            if((i >= 0 && j < 0) || (j >= 0 && i < 0))
                return 0;
            --i, --j;
        }
        return i < 0 && j < 0;
    }
};
