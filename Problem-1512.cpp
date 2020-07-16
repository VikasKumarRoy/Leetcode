// Problem - 1512

// https://leetcode.com/problems/number-of-good-pairs/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map <int, int> um;
        int ans = 0 ;
        for(int val: nums) {
            if(um.count(val))
                ans += um[val];
            um[val]++;
        }
        return ans;
    }
};
