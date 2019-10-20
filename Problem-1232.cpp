//Problem - 1232
// https://leetcode.com/problems/check-if-it-is-a-straight-line/

// O(n) time complexity and O(1) space complexity sol

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double slope = (double(coordinates[1][1] - coordinates[0][1])) / (coordinates[1][0] - coordinates[0][0]);
        for(int i = 2; i < coordinates.size(); i++) {
            double m = (double(coordinates[i][1] - coordinates[i-1][1])) / (coordinates[i][0] - coordinates[i-1][0]);
            if(m != slope)
                return false;
        }
        return true;
    }
};