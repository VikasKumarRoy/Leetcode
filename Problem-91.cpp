// Problem - 91

// https://leetcode.com/problems/decode-ways/

// O(n) time complexity and O(n) space complexity solution using top down dp

class Solution {
public:
    int recurr(string s, int pos, vector <int> &mem) {
        if(pos == s.length())
            return 1;
        if(mem[pos] != -1)
            return mem[pos];
        int a = 0, b = 0;
        if(s[pos] == '0')
            return 0;
        a = recurr(s, pos+1, mem);
        if(pos < s.length()-1) {
            int d = stoi(s.substr(pos, 2));
            if(d <= 26)
                b = recurr(s, pos+2, mem);
        }
        mem[pos] = a+b;
        return a + b;
    }
    
    int numDecodings(string s) {
        int n = s.length();
        vector <int> mem(n, -1);
        return recurr(s, 0, mem);
    }
};

// OR O(n) time complexity and O(n) space complexity solution using bottom approach

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector <int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for(int i = 2; i <= n; i++) {
            int f1 = stoi(s.substr(i-2, 2));
            int f2 = s[i-1]-'0';
            if(f2 >= 1)
                dp[i] += dp[i-1];
            if(f1 >= 10 && f1 <= 26) {
                dp[i] += (i > 1 ? dp[i-2] : 0);
            }
        }
        return dp[n];
    }
};
