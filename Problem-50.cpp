//Problem  - 50
// https://leetcode.com/problems/powx-n/

class Solution {
public:
    long double ans;
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        else if(n == 1)
            return x;
        if(n == -1)
            return 1/x;
        double temp = myPow(x, n/2);
        
        if(n%2) {
            if(n < 0)
                return temp * temp * 1/x;
            else
                return temp * temp * x;
        }

        else
            return temp * temp;
    }
};