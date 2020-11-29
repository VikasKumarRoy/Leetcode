// Problem - 1015

// https://leetcode.com/problems/smallest-integer-divisible-by-k/

// O(k) time complexity and O(k) space complexity solution

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k % 2 == 0 || k % 5 == 0)
            return -1;
        int len = 1, num = 1;
        unordered_set <int> remainder;
        while(num%k != 0) {
            int rem = num%k;
            if(remainder.count(rem))
                return -1;
            remainder.insert(rem);
            num = rem * 10 + 1;
            len++;
        }
        return len;
    }
};
