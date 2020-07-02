// Problem - 441

// https://leetcode.com/problems/arranging-coins/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int arrangeCoins(int n) {
        int steps = 0;
        long total = 0;
        while(total <= n) {
            steps++;
            total += steps;
        }
        return steps-1;
    }
};
