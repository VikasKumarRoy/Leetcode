// Problem - 12

// https://leetcode.com/problems/integer-to-roman/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    vector <pair <int, string>> table = { {1000, "M"},
                                          {900, "CM"}, 
                                          {500, "D"},
                                          {400, "CD"},
                                          {100, "C"},
                                          {90, "XC"},
                                          {50, "L"},
                                          {40, "XL"}, 
                                          {10, "X"}, 
                                          {9, "IX"},
                                          {5, "V"},
                                          {4, "IV"},
                                          {1, "I"} };
    
    string intToRoman(int num) {
        string str;
        for(int i = 0; i < table.size() && num != 0; i++) {
            if(table[i].first <= num) {
                int div = num / table[i].first;
                num -= div * table[i].first;
                while(div--)
                    str += table[i].second;
            }
        }
        return str;
    }
};