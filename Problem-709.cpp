//Problem - 709

// https://leetcode.com/problems/to-lower-case/

// O(n)  time complexity and O(1) space complexity sol

class Solution {
public:
    string toLowerCase(string str) {
        for(auto &c : str) {
            if(c >= 'A' && c <= 'Z')
                c = c + 32;
         }
        return str;
    }
};
