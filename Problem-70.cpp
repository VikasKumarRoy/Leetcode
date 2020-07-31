// Problem - 70

// https://leetcode.com/problems/climbing-stairs/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int climbStairs(int n) {
        int prev = 0, ans = 1;
        while(n--) {
            int temp = prev;
            prev = ans;
            ans += temp;
        }
        return ans;
    }
};
