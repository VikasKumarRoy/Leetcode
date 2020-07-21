// Problem - 1518

// https://leetcode.com/problems/water-bottles/

// O(logn) time complexity and O(1) space complexity solution

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0, balance = 0;
        int full = numBottles;
        while(full) {
            ans += full;
            int empty = full + balance;
            full = empty / numExchange;
            balance = empty % numExchange;
        }
        return ans;
    }
};
