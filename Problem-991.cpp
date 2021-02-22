// Problem - 991

// https://leetcode.com/problems/broken-calculator/

// O(log(Y)) time complexity and O(1) space complexity solution

class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(X == Y)
            return 0;
        else if(X > Y) {
            return X - Y;
        }
        if(Y%2 == 0)
            return 1 + brokenCalc(X, Y/2);
        else {
            return 1 + brokenCalc(X, Y+1);
        }
    }
};
