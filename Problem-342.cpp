// Problem - 342

// https://leetcode.com/problems/power-of-four/

// O(1) time complexity and O(1) space complexity solution

class Solution {
public:
    bool isPowerOfFour(int num) {
        int pos = -1;
        for(int i = 0; i < 32; i++) {
            if(num>>i & 1) {
                if(pos >= 0)
                    return false;
                pos = i;
            }
        }
        return pos%2 == 0;
    }
};
