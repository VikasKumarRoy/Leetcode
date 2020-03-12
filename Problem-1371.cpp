// Problem - 1371

// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/

// O(n) time complexity and O(n) space complexity solution

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
