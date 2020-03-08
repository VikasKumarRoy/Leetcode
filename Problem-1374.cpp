// Problem - 1374

// https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    string generateTheString(int n) {
        if(n&1)
            return string(n, 'a');
        return string(n-1, 'a') + 'b';
    }
};
