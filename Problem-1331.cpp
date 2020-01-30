// Problem - 1331

// https://leetcode.com/problems/rank-transform-of-an-array/

// O(nlogn) time complexity and O(n) space complexity solution

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map <int, vector <int>> m;
        for(int i = 0; i < arr.size(); i++)
            m[arr[i]].push_back(i);
        int ctr = 1;
        for(auto it = m.begin(); it != m.end(); it++) {  
            for(auto j : it->second)
                arr[j] = ctr;
            ctr++;
        }
        return arr;
    }
};