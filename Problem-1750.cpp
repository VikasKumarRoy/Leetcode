// Problem - 1750

// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int i = 0, j = n-1, ans = n;
        char c;
        while(i < j) {
            if(s[i] != s[j]) {
                ans = min(j-i+1, ans);
                break;
            }
            c = s[i];
            while(i < j-1 && s[i+1] == c) {
                i++;
            }
            while(i < j-1 && s[j-1] == c) {
                j--;
            }
            ans = min(j-i-1, ans);
            i++, j--;
        }
        return ans;
    }
};
