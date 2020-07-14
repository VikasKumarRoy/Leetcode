// Problem - 1344

// https://leetcode.com/problems/angle-between-hands-of-a-clock/

// O(1) time complexity and O(1) space complexity solution

class Solution {
public:
    double angleClock(int hour, int minute) {
        double minAng = minute * 6;
        double hourAng = (hour * 5 * 6) + (minute * 0.5);
        double angle = abs(hourAng - minAng);
        if (angle > 180)
            angle = 360 - angle;
        return angle;
    }
};
