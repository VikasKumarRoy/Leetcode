// Problem - 1641

// https://leetcode.com/problems/count-sorted-vowel-strings/

// O(n) time complexity and O(n) space complexity solution using top down dp

class Solution {
public:
    vector <char> vowels = {'a', 'e', 'i', 'o', 'u'};
    
    int dfs(int i, int n, string s, vector <vector <long long>>& mem) {
        if(i >= n)
            return 1;
        int len = s.length();
        if(len) {
            if(mem[i][s[len-1]-'a'] != -1) {
                return mem[i][s[len-1]-'a'];
            }
        }
        int ctr = 0;
        for(int i = 0; i < 5; i++) {
            if(len == 0 || s[len-1] <= vowels[i]) {
                ctr += dfs(len+1, n, s+vowels[i], mem);
            }
        }
        if(len)
            mem[i][s[len-1]-'a'] = ctr;
        return ctr;
    }
    
    int countVowelStrings(int n) {
        vector <vector <long long>> mem(n, vector <long long> (26, -1));
        return dfs(0, n, "", mem);
    }
};
