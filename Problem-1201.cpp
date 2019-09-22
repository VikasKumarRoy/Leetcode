//Problem - 1201
// https://leetcode.com/problems/ugly-number-iii/

// Time Complexity O(logn) and O(1) space complexity

class Solution {
public:
    
    int nthUglyNumber(int n, int a, int b, int c) {
        long A = a;
        long B = b;
        long C =  c;
        long AB = (A*B) / __gcd(A, B);
        long BC = (B*C) / __gcd(B, C);
        long AC = (A*C) / __gcd(A, C);
        long ABC = (A * BC) / __gcd(A, BC);
        int l = 0;
        int h = INT_MAX;
        while(l < h) {
            int mid = l + (h - l)/2;
            int ctr = mid/A + mid/B + mid/C - mid/AB - mid/BC - mid/AC + mid/ABC;
            if(ctr < n)
                l = mid + 1;
            else
                h = mid;
        }
        return l;
    }
};

