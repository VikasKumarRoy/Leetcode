  
// Problem - 470

// https://leetcode.com/problems/implement-rand10-using-rand7/

// O(1) time complexity and O(1) space complexity solution

class Solution {
public:
    int rand10() {
        int r = 31;
        while(r > 30) {
            r = 7 * (rand7()-1) + (rand7());
        }
        return r % 10 + 1;
    }
};
