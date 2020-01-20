// Problem - 1323

// https://leetcode.com/problems/maximum-69-number/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '6') {
                s[i] = '9';
                break;
            }
        }
        num = stoi(s);
        return num;
    }
};