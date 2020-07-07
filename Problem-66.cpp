// Problem - 66

// https://leetcode.com/problems/plus-one/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0, n = digits.size();
        digits[n-1] += 1;
        for(int i = n-1; i >= 0; i--) {
            digits[i] += carry;
            carry = digits[i]/10;
            if(digits[i] > 9) {
                digits[i] %= 10;
            }
        }
        if(carry) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
