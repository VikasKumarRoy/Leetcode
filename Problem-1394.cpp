// Problem - 1394

// https://leetcode.com/problems/find-lucky-integer-in-an-array/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map <int, int> um;
        for(int val : arr)
            um[val]++;
        int mx = -1;
        for(auto i : um) {
            if(i.first == i.second)
                mx = max(mx, i.first);
        }
        return mx;
    }
};
