// Problem - 1370

// https://leetcode.com/problems/increasing-decreasing-string/

// O(nlogn) time complexity and O(1) space complexity solution

class Solution {
public:
    string sortString(string s) {
        int n = s.length();
        string res = "";
        map <char, int> m;
        for(char c : s)
            m[c]++;
        while(1) {
            for(auto it = m.begin(); it != m.end(); it++) {
                if(it->second > 0) {
                    res += it->first;
                    it->second--;
                }
                if(res.length() == n)
                    return res;
            }
            for(auto it = m.rbegin(); it != m.rend(); it++) {
                if(it->second > 0) {
                    res += it->first;
                    it->second--;
                }
                if(res.length() == n)
                    return res;
            }
        }
        return res;
    }
};
