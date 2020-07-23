// Problem - 79

// https://leetcode.com/problems/word-search/

// O(n*m*4^len) time complexity and O(len) space complexity solution using dfs

class Solution {
public:
    
    int corX[8] = { -1, 0, 1, 0 }; 
    int corY[8] = { 0, -1, 0, 1 };
    
    bool dfs(int i, int j, vector<vector<char>>& v, string s, int pos) {
        if(pos == s.length())
            return true;
        if(i >= v.size() || j >= v[0].size() || i < 0 || j < 0 || s[pos] != v[i][j])
            return false;
        v[i][j] = '#';
        for(int k = 0; k < 4; k++) {
            int x = i + corX[k];
            int y = j + corY[k];
            if(dfs(x, y, v, s, pos+1))
                return true;
        }
        v[i][j] = s[pos];
        return false;
    }
    
    bool exist(vector<vector<char>>& v, string s) {
        int n = v.size();
        int m = v[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(dfs(i, j, v, s, 0))
                    return true;
            }
        }
        return false;
    }
};
