// Problem - 80

// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        int ctr = 1, num = nums[0];
        int i = 1, j = 1;
        while(j < nums.size()) {
            if(nums[j] == num) {
                num = nums[j];
                ctr++;
                if(ctr < 3)
                    swap(nums[i++], nums[j++]);
                else
                    j++;
            }
            else {
                num = nums[j];
                ctr = 1;
                swap(nums[i++], nums[j++]);
            }
        }
        return i;
    }
};
