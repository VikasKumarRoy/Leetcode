//Problem - 547
// https://leetcode.com/problems/friend-circles/

// O(n^2) time complexity and O(n) space complexity sol using disjoint set

class Solution {
public:
    int find(vector <int> &ds, int i) {
        if(ds[i] < 0)
            return i;
        return ds[i] = find(ds, ds[i]);
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        vector <int> ds(M.size(), -1);
        int ans = 0;
        for(int i = 0; i < M.size(); i++) {
            for(int j = i+1; j < M[i].size(); j++) {
                if(M[i][j])
                {
                    int m = find(ds, i);
                    int n = find(ds, j);
                    if(m != n) {
                        ds[m] = n;
                    }
                }
            }
        }
        for(int i = 0; i < ds.size(); i++) 
            if(ds[i] == -1)
                ans++;
        return ans;
    }
};