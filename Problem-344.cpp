 
// Problem - 344

// https://leetcode.com/problems/reverse-string/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i = 0; i < n/2; i++) {
            swap(s[i], s[n-i-1]);
        }
    }
};
