// Problem - 476

// https://leetcode.com/problems/number-complement/

// O(1) time complexity and O(1) space complexity solution

class Solution {
public:
    int findComplement(int num) {
        int ans = 0, i = 0;
        while(num) {
            ans |= ((num & 1) ^ 1) << i;
            num >>= 1;
            i++;
        }
        return ans;
    }
};

