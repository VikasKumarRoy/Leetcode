// Problem - 125

// https://leetcode.com/problems/valid-palindrome/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length()-1;
        while(i < j) {
            if(!isalnum(s[i]))
                i++;
            else if(!isalnum(s[j]))
                j--;
            else if(tolower(s[i]) != tolower(s[j]))
                return false;
            else
                i++, j--;
        }
        return true;
    }
};
