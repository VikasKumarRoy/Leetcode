// Problem - 1663

// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        while(n--) {
            int c = k - n;
            if(c > 26) {
                ans += 'a' + 25;
                k -= 26;
            }
            else {
                ans += 'a' + c - 1;
                k -= c;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
