// Problem - 29

// https://leetcode.com/problems/divide-two-integers/

// O((logn)^2) time complexity and O(1) space complexity solution

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int flag = 0;
        long ans = 0;
        if((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor >= 0))
            flag = 1;
        long dividend_ = abs(dividend);
        long divisor_ = abs(divisor);
        while(dividend_ >= divisor_) {
            long temp = divisor_;
            long ctr = 1;
            while(temp << 1 <= dividend_) {
                temp <<= 1;
                ctr <<= 1;
            }
            // As divisor_ * ctr = _dividend
            ans += ctr;
            dividend_ -= temp;
        }
        return flag ? -ans : ans;
    }
};
