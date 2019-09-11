//Problem - 238
// https://leetcode.com/problems/product-of-array-except-self/

// Time Complexity O(n) and O(1) space 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n);
        if(n < 2)
            return ans;
        ans[n-1] = 1;
        for(int i = n-2; i >= 0; i--)
            ans[i] = ans[i+1] * nums[i+1];
        int left = 1;
        for(int i = 0; i < n; i++) {
            ans[i] = left * ans[i];
            left *= nums[i];
        }
        return ans;
    }
};