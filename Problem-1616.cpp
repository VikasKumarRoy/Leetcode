// Problem - 1616

// https://leetcode.com/problems/split-two-strings-to-make-palindrome/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != s[s.length()-1-i])
                return false;
        }
        return true;
    }
    
    bool isPatternPalindrome(string s, int n) {
        int flag = 0;
        for(int i = 0; i < n/2; i++) {
            if(flag == 0) {
                if(s[i] != s[(2*n)-i-1])
                    flag = 1;
            }
            if(flag == 1) {
                if(s[i] != s[n-i-1])
                    flag = 2;
            }
            if(flag == 2) { 
                if(s[i+n] != s[(2*n)-i-1])
                    return false;
            }
            
        }
        return true;
    }
    
    bool checkPalindromeFormation(string a, string b) {
        if(isPalindrome(a) || isPalindrome(b))
            return true;
        string s1 = a + b, s2 = b + a;
        if(isPatternPalindrome(s1, a.length()) || isPatternPalindrome(s2, a.length()))
            return true;
        return false;
    }
};
