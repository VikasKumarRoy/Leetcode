// Problem - 139

// https://leetcode.com/problems/word-break/

// O(n^3) time complexity and O(n) space complexity solution using dp

class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector <bool> dp(s.length(), false);
        unordered_set <string> us(wordDict.begin(), wordDict.end());
        for(int i = 0; i < s.length(); i++) {
            for(int j = 0; j <= i; j++) {
                string sub = s.substr(j, i-j+1);
                if(us.count(sub)) {
                    if(j == 0)
                        dp[i] = true;
                    else if(dp[j-1] == true)
                        dp[i] = true;
                }
            }
        }
        return dp[s.length()-1];
    }
};
