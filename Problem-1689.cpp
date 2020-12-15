// Problem - 1689

// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

// O(len) time complexity and O(1) space complexity solution

class Solution {
public:
    int minPartitions(string n) {
        return *max_element(n.begin(), n.end()) - '0';
    }
};
