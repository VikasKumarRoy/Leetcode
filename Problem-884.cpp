// Problem - 884

// https://leetcode.com/problems/uncommon-words-from-two-sentences/

// O(n+m) time complexity and O(n+m) space complexity solution

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector <string> ans;
        unordered_map <string, int> um;
        stringstream ss(A + " " + B);
        string word;
        while(ss >> word)
            um[word]++;
        for(auto p : um)
            if(p.second == 1)
                ans.push_back(p.first);
        return ans;
    }
};