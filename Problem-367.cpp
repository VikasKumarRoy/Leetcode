// Problem - 367

// https://leetcode.com/problems/valid-perfect-square/

// O(log(n)) time complexity and O(1) space complexity solution using binary search

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)
            return true;
        long l = 0, r = num, mid;
        while(l <= r) {
            mid = (r-l)/2 + l;
            long prod = mid * mid;
            if(prod == num)
                return true;
            else if(prod > num)
                r = mid-1;
            else
                l = mid+1;
        }
        return false;
    }
};
