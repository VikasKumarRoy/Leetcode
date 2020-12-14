// Problem - 1688

// https://leetcode.com/problems/count-of-matches-in-tournament/

// O(logn) time complexity and O(1) space complexity solution

class Solution {
public:
    int numberOfMatches(int n) {
        int matches = 0;
        while(n != 1) {
            matches += n/2;
            n = ceil(n/2.0);
        }
        return matches;
    }
};
