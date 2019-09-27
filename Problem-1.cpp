//Problem - 1
// https://leetcode.com/problems/two-sum/

// Time Complexity O(n) and O(n) space using hash table

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans;
        unordered_map <int, int> hash;
        for(int i = 0; i < nums.size(); i++) {
            if(hash.find(target - nums[i]) != hash.end()) {
                ans.push_back(hash[target - nums[i]]);
                ans.push_back(i);
            }
            else
                hash[nums[i]] = i;
        }
        return ans;
    }
};


