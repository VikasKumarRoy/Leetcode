// Problem - 387

// https://leetcode.com/problems/first-unique-character-in-a-string/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map <char, int> um;
        for(char c : s)
            um[c]++;
        for(int i = 0; i < s.length(); i++) {
            if(um[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

// or single pass of array more efficient

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map <char, int> um;
        for(int i = 0; i < s.length(); i++) {
            if(um.find(s[i]) == um.end())
                um[s[i]] = i;
            else
                um[s[i]] = -1;
        }
        int ans = INT_MAX;
        for(auto p : um) {
            if(p.second >= 0)
                ans = min(ans, p.second);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};


