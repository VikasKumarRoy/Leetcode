//Problem - 1247
// https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/

// O(n) time complexity and O(1) space complexity sol

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int len = s1.length();
        int a = 0, b = 0;
        for(int i = 0; i < len; i++) {
            if(s1[i] != s2[i]) {
                if(s1[i] == 'x')
                    a++;
                else 
                    b++;
            }
        }
        int ans = 0;
        int c = a % 2;
        int d = b % 2;
        ans += a / 2;
        ans += b / 2;
        if(c == 1 && d == 1)
            ans += 2;
        else if(c == 1 || d == 1)
            return -1;
        return ans;
    }
};