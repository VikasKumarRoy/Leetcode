// Problem - 1296

// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

// O(nlogn) time complexity and O(n) space complexity solution

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k != 0)
            return 0;
        unordered_map <int, int> um;
        for(int val : nums) {
            um[val]++;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(um.find(nums[i]-1) == um.end() && um.find(nums[i]) != um.end()) {
                int sz = 0;
                while(sz < k) {
                    if(um.find(nums[i] + sz) != um.end()) {
                        um[nums[i] + sz]--;
                        if(um[nums[i]+sz] == 0)
                            um.erase(nums[i]+sz);
                        sz++;
                    }
                    else
                        return 0;
                }
                
            }
        }
        return um.empty() ? 1 : 0; 
    }
};