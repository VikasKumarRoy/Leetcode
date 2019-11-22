//Problem - 461

// https://leetcode.com/problems/hamming-distance/

// O(n) time complexity and O(1) space complexity sol

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        while(x || y) {
            cout << x <<" "<< y<< endl;
            if((x & 1 && !(y & 1)) || (!(x & 1) && y & 1))
                count++;
            x = x >> 1;
            y = y >> 1;
        }
        return count;
    }
};