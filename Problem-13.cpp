// Problem - 13

// https://leetcode.com/problems/roman-to-integer/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    unordered_map <char, int> um = { {'I', 1},
                                     {'V', 5}, 
                                     {'X', 10},
                                     {'L', 50},
                                     {'C', 100},
                                     {'D', 500},
                                     {'M', 1000} };
    
    int romanToInt(string s) {
        int ans = 0, ctr = 1;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] != s[i-1]) {
                if(um[s[i]] < um[s[i-1]])
                    ans += um[s[i-1]]*ctr;
                else
                    ans -= um[s[i-1]]*ctr;
                ctr = 1;
            }
            else
                ctr++;
        }
        ans += um[s[s.length()-1]]*ctr;
        return ans;
    }
};