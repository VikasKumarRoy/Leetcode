// Problem - 784

// https://leetcode.com/problems/letter-case-permutation/

// O(2^n) time complexity and O(n) space complexity solution

class Solution {
public:
    void generatePermutation(string s, int i, vector <string> &ans) {
        if(i == s.length()) {
            ans.emplace_back(s);
            return;
        }
        if(isdigit(s[i])) {
            generatePermutation(s, i+1, ans);
        }
        else {
            s[i] = tolower(s[i]);
            generatePermutation(s, i+1, ans);
            s[i] = toupper(s[i]);
            generatePermutation(s, i+1, ans);
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        vector <string> ans;
        generatePermutation(S, 0, ans);
        return ans;
    }
};
