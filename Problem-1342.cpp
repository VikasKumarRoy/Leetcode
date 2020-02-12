// Problem - 1342

// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int numberOfSteps (int num) {
        int steps = 0;
        while(num != 0) {
            if(num&1)
                num -= 1;
            else
                num /= 2;
            steps++;
        }
        return steps;
    }
};