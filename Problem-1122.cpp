//Problem  - 1122

// https://leetcode.com/problems/relative-sort-array/

// O(nlogn) time complexity and O(n) space solution 

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        multiset <int> s;
        vector <int> ans;
        unordered_map <int, int> um;
        for(int val : arr2)
            um[val] = 0;
        for(int val : arr1) {
            if(um.find(val) != um.end())
                um[val]++;
            else
                s.insert(val);
        }
        for(int val : arr2) {
            while(um[val]--)
                ans.push_back(val);
        }
        ans.insert(ans.end(), s.begin(), s.end());
        return ans;
    }
};
