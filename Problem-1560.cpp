// Problem - 1560

// https://leetcode.com/problems/most-visited-sector-in-a-circular-track/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int start = rounds[0];
        int end = rounds[rounds.size()-1];
        vector <int> ans;
        if(start <= end) {
            for(int i = start; i <= end; i++)
                ans.push_back(i);
        }
        else {
            for(int i = 1; i <= end; i++) {
                ans.push_back(i);
            }
            for(int i = start; i <= n; i++)
                ans.push_back(i);
        }
        return ans;
    }
};
   
