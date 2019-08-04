//Problem  - 1144
// https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        if(nums.size() <= 2)
            return 0;
        int a = 0, b = 0;
        for(int i = 1; i < nums.size(); i += 2) {
            if (i < nums.size()-1 && (nums[i] >= nums[i-1] || nums[i] >= nums[i+1]))
                a += nums[i] - min(nums[i-1], nums[i+1]) + 1;
            else if(i+1 >= nums.size() && nums[i] >= nums[i-1])
                a += nums[i] - nums[i-1] + 1;
        }
        for(int i = 0; i < nums.size(); i += 2) {
            if (i == 0 && nums[i] >= nums[i+1])
                b += nums[i] - nums[i+1] + 1;
            else if(i !=0 && i < nums.size()-1 && (nums[i] >= nums[i-1] || nums[i] >= nums[i+1]))
                b += nums[i] - min(nums[i-1], nums[i+1]) + 1;
            else if(i+1 >= nums.size() && nums[i] >= nums[i-1])
                b += nums[i] - nums[i-1] + 1;
    } 
        cout<<a<<b;
        return min(a, b);
    }
};