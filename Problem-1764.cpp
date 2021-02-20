// Problem - 1764

// https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/

// O(n+m) time complexity and O(1) space complexity solution

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = nums.size();
        int i = 0, numIndex = 0;
        while(i < groups.size() && numIndex < n) {
            int j = 0;
            int ctr = 0;
            int sz = groups[i].size();
            int k = numIndex;
            while(k < n && j < sz && nums[k] == groups[i][j]) {
                ctr++, j++, k++;
            }
            if(ctr == sz) {
                i++;
                numIndex += ctr;
            }
            else {
                numIndex++;
            }
        }
        return i == groups.size();
    }
};
