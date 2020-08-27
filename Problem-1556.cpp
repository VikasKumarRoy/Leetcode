// Problem - 1556

// https://leetcode.com/problems/thousand-separator/

// O(length(n)) time complexity and O(1) space complexity solution

class Solution {
public:
    string thousandSeparator(int n) {
        string ans;
        if(n == 0)
            return "0";
        int ctr = 0;
        while(n) {
            if(ctr == 3) {
                ans = '.' + ans;
                ctr = 0;
            }
            ctr++;
            int d = n % 10;
            n /= 10;
            ans = to_string(d) + ans;
        }
        return ans;
    }
};
