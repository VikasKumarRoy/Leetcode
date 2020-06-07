// Problem - 398

// https://leetcode.com/problems/random-pick-index/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    unordered_map <int, vector <int>> um; 
    
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            um[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        auto it = um.find(target);
        int r = rand() % it->second.size();
        return it->second[r];
    }
};
