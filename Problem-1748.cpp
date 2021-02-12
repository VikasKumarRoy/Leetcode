// Problem - 1748

// https://leetcode.com/problems/sum-of-unique-elements/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map <int, int> um;
        for(int val : nums)
            um[val]++;
        int ans = 0;
        for(auto it : um) {
            if(it.second == 1)
                ans += it.first;
        }
        return ans;
    }
};
