// Problem - 858

// https://leetcode.com/problems/mirror-reflection/

// O(p) time complexity and O(1) space complexity solution

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int x = 0, y = 0;
        while (true) {
            y += q;

            // If left then right. If right then left.
            if (x == 0) x = p;
            else x = 0;

            // If we hited any corner.
            if (y % p == 0) {
                if (y / p % 2 == 0) return 0;
                if (x == p) return 1;
                else return 2;
            }
        }
    }
};
