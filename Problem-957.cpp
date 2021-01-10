// Problem - 957

// https://leetcode.com/problems/prison-cells-after-n-days/

// O(1) time complexity and O(1) space complexity solution

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_map <int, int> um;
        int num = 0;
        int ctr = 0;
        for(int i = 0; i < 8; i++) {
            num |= cells[i] << i;
        }
        int cycleSize = 0;
        while(ctr < N) {
            int x = 0;
            ctr++;
            for(int i = 1; i < 7; i++) {
                x |= (((num >> (i-1))&1)  == ((num >> (i+1))&1) ? 1 : 0) << i;
            }
            if(um.count(x) && cycleSize == 0) {
                cycleSize = ctr - um[x];
                N %= cycleSize;
                cout << N;
                if(N == 0)
                    N = cycleSize;
                ctr = 1;
            }
            else {
                um[x] = ctr;
            }
            num = x;
        }
        vector <int> ans;
        for(int i = 0; i < 8; i++) {
            ans.push_back((num >> i)&1);
        }
        return ans;
    }
};
