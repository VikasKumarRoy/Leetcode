// Problem - 371

// https://leetcode.com/problems/sum-of-two-integers/

// O(1) time complexity and O(1) space complexity solution

class Solution {
public:
    int getSum(int a, int b) {
        int c; 
        while(b !=0 ) {
            c = (a&b);
            a = a ^ b;
            b = (unsigned int)(c)<<1;
        }
        return a;
    }
};