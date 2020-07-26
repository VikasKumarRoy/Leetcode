// Problem - 258

// https://leetcode.com/problems/add-digits/

// O(logn) time complexity and O(1) space complexity solution

class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while(n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    
    int addDigits(int num) {
        while(num > 9) {
            num = digitSum(num);
        }
        return num;
    }
};
