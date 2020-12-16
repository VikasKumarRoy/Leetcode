// Problem - 1685

// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n), right(n);
        right[n-1] = nums[n-1];
        int sum = 0;
        for(int i = n-2; i >= 0; i--) {
            right[i] = right[i+1] + nums[i];
        }
        for(int i = 0; i < n; i++) {
            ans[i] =  (right[i] - (n-i)*nums[i]) + (nums[i]*i - sum);
            sum += nums[i];
        }
        return ans;
    }
};

// O(1) space solution

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n);
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        for(int i = 0; i < n; i++) {
            ans[i] =  (rightSum - (n-i)*nums[i]) + (nums[i]*i - leftSum);
            leftSum += nums[i];
            rightSum -= nums[i];
        }
        return ans;
    }
};
