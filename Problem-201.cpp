// Problem - 201

// https://leetcode.com/problems/bitwise-and-of-numbers-range/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        while(m != n) {
            m >>= 1;
            n >>= 1;
            shift++;
        }
        return m << shift;
    }
};
