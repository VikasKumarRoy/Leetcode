// Problem - 820

// https://leetcode.com/problems/short-encoding-of-words/

// O(n^2) time complexity and O(n) space complexity solution

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        unordered_set <string> us;
        for(int i = 0; i < n; i++) {
            int flag = 0;
            for(int j = 0; j < n; j++) {
                if(i == j)
                    continue;
                if(words[i].length() < words[j].length()) {
                    int d = words[j].length() - words[i].length();
                    if(words[j].substr(d) == words[i])
                        flag = 1;
                }
                if(flag)
                    break;
            }
            if(!flag) {
                us.insert(words[i]);
            }
        }
        int ans = 0;
        for(auto it : us) {
            ans += it.length();
        }
        return ans + us.size();
    }
};
