// Problem - 1297

// https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/

// O(n) time complexity and O(n) space complexity solution using sliding window

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int ans = 0;
        unordered_map <string, int> um;
        int freq[26] = {0};
        int i = 0, j = 0, count = 0;
        while(j < s.length()) {
            if(freq[s[j]-'a'] == 0)
                    count++;
            freq[s[j]-'a']++;
            if((j - i + 1) > minSize) {
                cout << "l;";
                if(--freq[s[i]-'a'] == 0)
                    count--;
                i++;
            }
            if((j - i  + 1) >= minSize && count <= maxLetters)
                um[s.substr(i, j-i+1)]++;
            j++;
        }
        for(auto p : um) {
            cout << p.first<<endl;
            ans = max(ans, p.second);
        }
        return ans;
    }
};