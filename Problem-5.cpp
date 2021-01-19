// Problem - 5

// https://leetcode.com/problems/longest-palindromic-substring/

// O(n^2) time complexity and O(n^2) space complexity solution

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector <vector <bool>> dp(n, vector <bool> (n, false));
        for(int i = 0; i < n; i++)
            dp[i][i] = true;
        string ans(1, s[0]);
        for(int len = 1; len < n; len++) {
            for(int i = 0; i + len < n; i++) {
                if(s[i] == s[i+len]) {
                    dp[i][i+len] = len == 1 ? true : (dp[i+1][i+len-1]);
                    if(dp[i][i+len]) {
                        ans = s.substr(i, len+1);
                    }
                }
                else {
                    dp[i][i+len] = false;
                }
            }
        }
        return ans;
    }
};

// OR O(n^2) time complexity and O(1) space complexity solution

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string ans(1, s[0]);
        int mx = 1;
        for(int i = 0; i < n; i++) {
            int j = i-1;
            int k = i+1;
            while(j >= 0 && k < n && s[j] == s[k]) {
                if(k-j+1 > mx) {
                    mx = k-j+1;
                    ans =  s.substr(j, mx);
                }
                j--, k++;
            }
            j = i, k = i+1;
            while(j >= 0 && k < n && s[j] == s[k]) {
                if(k-j+1 > mx) {
                    mx = k-j+1;
                    ans =  s.substr(j, mx);
                }
                j--, k++;
            }
        }
        return ans;
    }
};
