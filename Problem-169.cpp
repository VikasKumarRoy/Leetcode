// Problem - 169

// https://leetcode.com/problems/majority-element/

// O(n) time complexity and O(1) space complexity solution

//MOORE's voting algo

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = 0;
        int ctr = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[maj])
                ctr++;
            else
                ctr--;
            if(ctr == 0) {
                maj = i;
                ctr = 1;
            }
        }
        return nums[maj];
    }
};