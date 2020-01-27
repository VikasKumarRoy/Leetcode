// Problem - 500

// https://leetcode.com/problems/keyboard-row/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    
    int map [26]= {2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};

    vector<string> findWords(vector<string>& words) {
        vector <string> ans;
        for(int i = 0; i < words.size(); i++) {
            int m = map[tolower(words[i][0]) - 'a'];
            int flag = 1;
            for(int j = 1; j < words[i].length(); j++)
                if(map[tolower(words[i][j]) - 'a'] != m) {
                    flag = 0;
                    break;
                }
            if(flag)
                ans.push_back(words[i]);
        }
        return ans;
    }
};