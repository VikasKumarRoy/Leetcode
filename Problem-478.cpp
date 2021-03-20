// Problem - 478

// https://leetcode.com/problems/generate-random-point-in-a-circle/

// O(1) time complexity and O(1) space complexity solution

class Solution {
public:
    double R, X, Y;
    
    Solution(double radius, double x_center, double y_center) {
        R = radius;
        X = x_center;
        Y = y_center;
    }
    
    vector<double> randPoint() {
        double dist = sqrt((double)random()/ RAND_MAX) * R;
        double deg = 2 * M_PI * (double)random()/ RAND_MAX;
        return vector<double> {X + dist*cos(deg), Y + dist*sin(deg)};
    }
};
