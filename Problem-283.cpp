// Problem - 283

// https://leetcode.com/problems/move-zeroes/

// O(n) time complexity and O(1) space complexity solution where n = no. of chars

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] == 0) {
                int j = i+1;
                while(j < nums.size() && nums[j] == 0) {
                    j++;
                }
                if(j < nums.size()) {
                    swap(nums[i], nums[j]);
                }
            }
            i++;
        }
    }
};
