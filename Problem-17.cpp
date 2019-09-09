//Problem - 17
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

// O(3^n * 4^m) time complexity solution 

class Solution {
public:
    unordered_map <int, string> mp = {{2, "abc"},
                                      {3, "def"},
                                      {4, "ghi"},
                                      {5, "jkl"},
                                      {6, "mno"},
                                      {7, "pqrs"},
                                      {8, "tuv"},
                                      {9, "wxyz"}};
    
    vector <string> ans;
    
    void backtrack(string digits, int ind, string str) {
        if(ind == digits.length()) {
            ans.push_back(str);
            return;
        }
        string temp = mp[digits[ind] - '0'];
        for(int i = 0; i < temp.length(); i++) {
            backtrack(digits, ind+1, str + temp[i]);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return ans;
        backtrack(digits, 0, "");
        return ans;
    }
};