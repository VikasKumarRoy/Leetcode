// Problem - 526

// https://leetcode.com/problems/beautiful-arrangement/

// O(k) time complexity and O(n) space complexity solution using backtracking where k refers to the number of valid permutations

class Solution {
public:
    int ans = 0;
    
    void dfs(int pos, int n, vector <bool>& v) {
        if(pos > n) {
            ans++;
            return;
        }
        for(int i = 1; i <= n; i++) {
            if(!v[i]) {
                if(i % pos == 0 || pos % i == 0) {
                    v[i] = true;
                    dfs(pos+1, n, v);
                }
                v[i] = false;
            }
        }
    }
    
    int countArrangement(int n) {
        vector <bool> v(n+1, false);
        dfs(1, n, v);
        return ans;
    }
};


