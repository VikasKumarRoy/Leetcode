// Problem - 49

// https://leetcode.com/problems/group-anagrams/

// O(n*m) time complexity and O(n) space complexity solution where n*m = total no. of chars
// Used hashset and counting sort for better complexity

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector <string>> um;
        vector <vector<string>> ans;
        for(int i = 0; i < strs.size(); i++) {
            vector <int> freq(26, 0);
            for(char c : strs[i])
                freq[c-'a']++;
            string mask = "";
            for(int j = 0; j < 26; j++) {
                while(freq[j]--)
                    mask += ('a'+j);
            }
            um[mask].push_back(strs[i]);
        }
        for(auto it : um)
            ans.push_back(it.second);
        return ans;
    }
};
