// Problem - 1356

// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

// O(nlogn) time complexity and O(1) space complexity solution

class Solution {
public:
    
    bool static comp(int a, int b)
    {
        int ca = __builtin_popcount(a);
        int cb = __builtin_popcount(b);

        if(ca == cb)
            return a <= b;
        return ca < cb;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};
