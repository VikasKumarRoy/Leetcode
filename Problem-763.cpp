// Problem - 763

// https://leetcode.com/problems/partition-labels/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector <int> freq(26, 0);
        for(char c : S) {
            freq[c-'a']++;
        }
        int i = 0, j = 0, last = 0;
        vector <int> ans;
        while(j < S.length()) {
            freq[S[j]-'a']--;
            if(S[i] == S[j]) {
                while(freq[S[i]-'a'] == 0 && i < j)
                    i++;
                if(i == j && freq[S[i]-'a'] == 0) {
                    ans.push_back(j-last+1);
                    i++;
                    last = j+1;
                }
            }
            j++;
        }
        return ans;
    }
};
