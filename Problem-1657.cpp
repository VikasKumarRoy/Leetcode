// Problem - 1657

// https://leetcode.com/problems/determine-if-two-strings-are-close/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length())
            return false;
        int n = word1.length();
        unordered_map <char, int> um1, um2;
        for(int i = 0; i < n; i++) {
            um1[word1[i]]++;
            um2[word2[i]]++;
        }
        unordered_set <int> us;
        for(auto it: um1) {
            us.insert(it.second);
        }
        if(um1.size() != um2.size())
            return false;
        for(auto it: um2) {
            if(!um1.count(it.first) || !us.count(it.second))
                return false;
        }
        return true;
    }
};
