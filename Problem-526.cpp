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

// By using int to store index of visited and using memorization

class Solution {
public:
    int ans = 0;
    
    int dfs(int ind, int n, vector <vector <int>>& mem, int used) {
        if(ind > n) {
            ans++;
            return 1;
        }
        if(mem[ind][used] != -1)
            return mem[ind][used];
        int ctr = 0;
        for(int i = 1; i <= n; i++) {
            if(((used >> i) & 1) == 0) {
                if(i % ind == 0 || ind % i == 0) {
                    ctr += dfs(ind+1, n, mem, used | (1 << i));
                }
            }
        }
        mem[ind][used] = ctr;
        return mem[ind][used];
    }
    
    int countArrangement(int n) {
        vector <vector <int>> mem(n+1, vector <int> (1 << (n+1), -1));
        return dfs(1, n, mem, 0);
        return ans;
    }
};

