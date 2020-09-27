// Problem - 1593

// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/

// O(2^n) time complexity and O(n) space complexity solution

class Solution {
public:
    int mx = 0;
    
    void fun(string s, unordered_set <string> us, int ind) {
        if(ind >= s.length())
            return;
        for(int i = 1; i <= s.length(); i++) {
            if(i + ind - 1 >= s.length())
                break;
            string sub = s.substr(ind, i);
            if(us.count(sub))
                continue;
            us.insert(sub);
            if(i + ind == s.length()) {
                mx = max(mx, (int)us.size());
            }
            fun(s, us, ind + i);
            us.erase(sub);
        }
    }
    
    int maxUniqueSplit(string s) {
        unordered_set <string> us;
        fun(s, us, 0);
        return mx;
    }
};
