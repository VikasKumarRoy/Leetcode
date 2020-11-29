// Problem - 1306

// https://leetcode.com/problems/jump-game-iii/

// O(n) time complexity and O(n) space complexity solution using dfs

class Solution {
public:
    bool dfs(vector <int>& arr, vector <bool>& visited, int pos) {
        if(pos < 0 || pos >= visited.size())
            return false;
        if(visited[pos])
            return false;
        if(arr[pos] == 0) {
            return true;
        }
        visited[pos] = true;
        return dfs(arr, visited, pos + arr[pos]) || dfs(arr, visited, pos - arr[pos]); 
    }
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector <bool> visited(n, false);
        return dfs(arr, visited, start);
    }
};
