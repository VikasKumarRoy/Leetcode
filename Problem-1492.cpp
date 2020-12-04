// Problem - 1492

// https://leetcode.com/problems/the-kth-factor-of-n/

// O(sqrt(n)) time complexity and O(1) space complexity solution

class Solution {
public:
    int kthFactor(int n, int k) {
        int c = 1;
        for(int i = 1; i < sqrt(n); i++) {
            if(n%i == 0)
                k--;
            if(k == 0)
                return i;
        }
        for(int i = sqrt(n); i >= 1; i--) {
            if(n%i == 0)
                k--;
            if(k == 0)
                return n/i;
        }
        return -1;
    }
};
