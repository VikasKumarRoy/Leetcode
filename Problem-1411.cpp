 
// Problem - 1411

// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/

// O(n) time complexity and O(1) space complexity solution using DP

class Solution {
public:
    const int mod = 1e9 + 7;
    
    int numOfWays(int n) {
        long xyx = 6;                                    //121, 131, 212, 232, 313, 323 
        long xyz = 6;                                    //123, 321, 213, 231, 312, 321
        int ans = 0;
        while(--n) {
            long XYX = 3 * xyx + 2 * xyz;
            long XYZ = 2 * xyx + 2 * xyz;
            xyx = XYX % mod;
            xyz = XYZ % mod;
        }
        return (xyx + xyz) % mod;
    }
};
