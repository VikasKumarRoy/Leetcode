//Problem - 1282

// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groups) {
        vector <vector<int>> res;
        unordered_map <int, vector<int>> um;
        for(int i = 0; i < groups.size(); i++)
            um[groups[i]].push_back(i);
        for(auto p : um) {
            for(int i = 0; i < um[p.first].size(); i += p.first)
                res.push_back(vector <int>(um[p.first].begin()+i, um[p.first].begin()+i+p.first));
        }
        return res;
    }
};