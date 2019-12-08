//Problem - 1281

// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

// O(digits) time complexity and O(1) space complexity solution

class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1;
        int sum = 0;
        while(n) {
            int d = n % 10;
            prod *= d;
            sum += d;
            n /= 10;
        }
        return prod - sum;
    }
};