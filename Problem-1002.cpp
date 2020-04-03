// Problem - 1030

// https://leetcode.com/problems/find-common-characters/

// O(n) time complexity and O(1) space complexity solution where n = no. of chars

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector <int> common(26, 0);
        vector <string> ans;
        for(char c : A[0]) {
            common[c-'a']++;
        }
        for(int i = 1; i < A.size(); i++) {
            vector <int> freq(26, 0);
            for(char c : A[i]) {
                freq[c-'a']++;
            }
            for(int j = 0; j < 26; j++) {
                common[j] = min(common[j], freq[j]);
            }
        }
        for(int i = 0; i < 26; i++) {
            while(common[i]--)
                ans.push_back(string(1, i+'a'));
        }
        return ans;
    }
};

