// Problem - 1680

// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    const int mod = 1e9+7;
    
    int concatenatedBinary(int n) {
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            int x = i, len = 0;
            while (x > 0) {
                ++len;
                x /= 2;
            }
            ans = (ans << len) % mod + i;
        }
        return ans % mod;
    }
};
