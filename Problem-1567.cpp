// Problem - 1567

// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, j = 0;
        vector <int> suff(n, 0);
        int a = 0, b = 0;
        for(int i = n-1; i >= 0; i--) {
            if(nums[i] < 0)
                a++;
            else if(nums[i] == 0)
                a = 0;
            suff[i] = a;
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                j = i+1;
                b = 0;
            }
            else if(nums[i] < 0) {
                b++;
                suff[j]--;
                if((b&1) && suff[j] == 0) {
                    while(nums[j] >= 0)
                        j++;
                    j++;
                    b--;
                }
            }
            if(i-j+1 > 0)
                ans = max(i-j+1, ans);
        }
        return ans;
    }
};
