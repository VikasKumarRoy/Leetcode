// Problem - 1551

// https://leetcode.com/problems/minimum-operations-to-make-array-equal/

// O(1) time complexity and O(1) space complexity solution

class Solution {
public:
    int minOperations(int n) {
        if(n & 1)
            return pow((n+1)/2, 2) - (n+1)/2;
        else
            return (n/2) * (n/2); 
    }
};
