// Problem - 231

// https://leetcode.com/problems/power-of-two/

// O(1) time complexity and O(1) space complexity solution

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0)
            return false;
        return !(n&(n-1)); 
    }
};
