// Problem - 1679

// https://leetcode.com/problems/max-number-of-k-sum-pairs/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map <int, int> um;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(um[k-nums[i]]) {
                ans++;
                um[k-nums[i]]--;
            }
            else
                um[nums[i]]++;
        }
        return ans;
    }
};
