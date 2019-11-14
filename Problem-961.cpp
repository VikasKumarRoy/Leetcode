//Problem - 961

// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

// O(n)  time complexity and O(n) space complexity sol

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int n = A.size();
        unordered_map <int, int> um;
        for(auto i : A)
            um[i]++;
        for(auto p : um)
            if(p.second == n/2)
                return p.first;
        return -1;
    }
};
