// Problem - 1437

// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int ctr = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]) {
                if(ctr < k)
                    return false;
                ctr = 0;
            }
            else {
                ctr++;
            }
        }
        return true;
    }
};
