// Problem - 1345

// https://leetcode.com/problems/jump-game-iv/

// O(n) time complexity and O(n) space complexity solution using bfs

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int steps = 0;
        int n = arr.size();
        if(n == 1)
            return 0;
        unordered_map <int, vector <int>> um;
        for(int i = 0; i < n; i++) {
            um[arr[i]].push_back(i);
        }
        queue <int> q;
        q.push(0);
        vector <bool> visited(n);
        visited[0] = true;
        while(!q.empty()) {
            steps++;
            int sz = q.size();
            while(sz--) {
                int i = q.front();
                q.pop();
                if(i > 0 && !visited[i-1]) {
                    visited[i-1] = true;
                    q.push(i-1);
                }
                if(i < n-1 && !visited[i+1]) {
                    if(i+1 == n-1)
                        return steps;
                    visited[i+1] = true;
                    q.push(i+1);
                }
                for(int u : um[arr[i]]) {
                    if(u == n-1)
                        return steps;
                    if(!visited[u]) {
                        visited[u] = true;
                        q.push(u);
                    }
                }
                um[arr[i]] = {};
            }
        }
        return steps;
    }
};
