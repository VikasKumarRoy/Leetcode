// Problem - 997

// https://leetcode.com/problems/find-the-town-judge/

// Time Complexity O(n + T) and O(n) space solution

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector <int> degree(N+1, 0);
        for(auto v : trust) {
            degree[v[0]]--;
            degree[v[1]]++;
        }
        for(int i = 1; i < N+1; i++) {
            if(degree[i] == N-1)
                return i;
        }
        return -1;
    }
};
