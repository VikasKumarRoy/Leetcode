// Problem - 754

// https://leetcode.com/problems/reach-a-number/

// O(sqrt(n)) time complexity and O(1) space complexity solution

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int steps = 0;
        int sum = 0;
        while(sum < target) {
            steps++;
            sum += steps;
        }
        while((target-sum)%2 != 0) {
            steps++;
            sum += steps;
        }
        return steps;
    }
};
