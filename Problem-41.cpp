//Problem - 41

// https://leetcode.com/problems/first-missing-positive/

// O(n) time complexity and O(1) space complexity sol

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 1;
        int i = 0, j = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] <= 0) {
	            swap(nums[i], nums[j]);
	            nums[j++] = 5;
	        }
        }
        for(int i = j; i < n; i++) {
            if(abs(nums[i])-1 < n && nums[abs(nums[i])-1] > 0)
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] >= 0)
                return i+1;
        }
        return n+1;
    }
};