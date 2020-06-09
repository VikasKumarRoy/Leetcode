// Problem - 392

// https://leetcode.com/problems/is-subsequence/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while(i < s.length() && j < t.length()) {
            if(s[i] == t[j])
                i++;
            j++;
        }
        return i == s.length();
    }
};

// Follow Up
// O(n) for pre-processing and O(MKlogN)

class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map <char, vector <int>> hash;
        for(int i = 0; i < t.length(); i++)
            hash[t[i]].push_back(i);
        int prev = -1;
        for(char c : s) {
            auto it = hash.find(c);
            if(it == hash.end())
                return false;
            vector <int> v = it->second;
            auto i = upper_bound(v.begin(), v.end(), prev) - v.begin();
            if(i == v.size())
                return false;
            prev = v[i];
        }
        return true;
    }
};
