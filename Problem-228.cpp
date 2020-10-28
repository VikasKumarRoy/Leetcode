// Problem - 228

// https://leetcode.com/problems/summary-ranges/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector <string> ans;
        nums.push_back(INT_MAX);
        int start = 0;
        for(int i = 1; i < nums.size(); i++) {
            long curr = nums[i];
            long prev = nums[i-1];
            if(curr-prev != 1) {
                if(nums[i-1] == nums[start]) {
                    ans.push_back(to_string(nums[start]));
                }
                else {
                    ans.push_back(to_string(nums[start])+"->"+to_string(nums[i-1]));
                }
                start = i;
            }
        }
        return ans;
    }
};
