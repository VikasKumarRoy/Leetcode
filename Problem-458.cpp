// Problem - 458

// https://leetcode.com/problems/poor-pigs/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int T = minutesToTest/minutesToDie;
        int x = 0;
        while(pow(T+1, x) < buckets)
            x++;
        return x;
    }
};
