//Problem - 1108

// https://leetcode.com/problems/defanging-an-ip-address/

// O(n)  time complexity for dfs and O(n) space complexity sol

class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for(char c : address) {
            if(c == '.')
                ans += "[.]";
            else
                ans += c;
        }
        return ans;
    }
};
