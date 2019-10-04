//Problem - 3
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Time Complexity O(n) and O(min(m, n)) using hashmap where m is set of chars

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, ans = 0;
        unordered_map <char, int> m;
        while(j < s.length()) {
            if(m.find(s[j]) == m.end())
                ans = max(ans, j - i + 1);
            else {
                if(s[i] == s[j])
                    i++;
                else {
                    while(i < m[s[j]])
                        m.erase(s[i++]);
                    i++;
                }
            }
            m[s[j]] = j;
            j++;
        }
        return ans;
    }
};

// OR single pass

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, ans = 0;
        unordered_map <char, int> m;
        while(j < s.length()) {
            if(m.find(s[j]) == m.end() || m[s[j]] < i)
                ans = max(ans, j - i + 1);
            else {
                if(s[i] == s[j])
                    i++;
                else
                    i = m[s[j]] + 1;
            }
            m[s[j]] = j;
            j++;
        }
        return ans;
    }
};



