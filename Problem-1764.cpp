// Problem - 1764

// https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/

// O(n+m) time complexity and O(1) space complexity solution

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = nums.size();
        int i = 0, valid = 0, k = 0;
        while(i < groups.size() && k < n) {
            int j = 0;
            int ctr = 0;
            int sz = groups[i].size();
            int temp = k;
            while(k < n && j < sz) {
                if(groups[i][j] == nums[k]) {
                    ctr++;
                    j++, k++;
                }
                else {
                    j = 0;
                    ctr = 0;
                    k = temp+1;
                }
            }
            if(ctr == sz) {
                valid++;
                k += ctr;
            }
            
            i++;
        }
        if(i == groups.size())
            return true;
        return false;
    }
};
