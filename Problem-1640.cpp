// Problem - 1640

// https://leetcode.com/problems/check-array-formation-through-concatenation/

// O(n+m) time complexity and O(m) space complexity solution

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map <int, vector <int>> um;
        for(auto v : pieces) {
            um[v[0]] = v;
        }
        int i = 0;
        while(i < arr.size()) {
            auto it = um.find(arr[i]);
            if(it == um.end())
                return false;
            for(auto val : it->second) {
                if(val != arr[i++])
                    return false;
            }
        }
        return true;
    }
};
