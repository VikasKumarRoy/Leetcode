//Problem  - 1138
//https://leetcode.com/problems/alphabet-board-path/

#include<bits/stdc++.h>
class Solution {
public:
    
    
    
    string alphabetBoardPath(string target) {
        unordered_map < char, pair <int, int> > mp;
        int ctr = 0;
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++) {
                mp['a' + ctr] = {i ,j};
                ctr++;
            }
        mp['z'] = {5, 0};
        pair <int, int> src = {0, 0};
        string ans;
        for(int i = 0; i < target.length(); i++) {
            pair <int, int> dest = mp[target[i]];
            int x = src.first - dest.first;
            int y = src.second - dest.second;
            if(y > 0) {
                string str(y, 'L');
                ans += str;
            }
            if(x > 0) {
                string str(x, 'U');
                ans += str;
            }
            if(y < 0) {
                string str(abs(y), 'R');
                ans += str;
            }
            
            if(x < 0) {
                string str(abs(x), 'D');
                ans += str;
            }
            ans += "!";
            src = dest;
        }
        return ans;
    }
};