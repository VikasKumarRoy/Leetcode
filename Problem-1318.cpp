// Problem - 1318

// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

// O(1) time complexity and O(1) space complexity solution

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while(a || b || c) {
            if(!(c & 1)) {
                if((a & 1) && (b & 1))
                    ans += 2;
                else if((a & 1) || (b & 1))
                    ans++;
            }
            if(c & 1) {
                if(!(a & 1) && !(b & 1))
                    ans++;
            }   
            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }
        return ans;
    }
};