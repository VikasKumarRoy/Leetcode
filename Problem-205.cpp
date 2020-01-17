// Problem - 205

// https://leetcode.com/problems/isomorphic-strings/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_set <char> us;
        unordered_map <char, char> um;
        for(int i = 0; i < s.length(); i++) {
            if(um.find(s[i]) == um.end()) {
                if(us.count(t[i]))
                    return 0;
                um[s[i]] = t[i];
                us.insert(t[i]);
            } else {
                if(um[s[i]] != t[i])
                    return 0;
            }
        }
        return 1;
    }
};