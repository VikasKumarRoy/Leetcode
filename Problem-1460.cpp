// Problem - 1460

// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map <int, int> um;
        for(int val : arr)
            um[val]++;
        for(int val : target) {
            if(um[val] <= 0)
                return false;
            um[val]--;
        }
        return true;
    }
};
