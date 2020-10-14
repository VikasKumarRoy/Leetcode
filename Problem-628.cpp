// Problem - 628

// https://leetcode.com/problems/maximum-product-of-three-numbers/

// O(nlogn) time complexity and O(1) space complexity solution

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(nums[0]*nums[1]*nums[n-1], nums[n-1]*nums[n-2]*nums[n-3]);
    }
};

//  OR  O(n) time complexity and O(1) space solution

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int mx, mx2, mx3, mn, mn2;
        mx = mx2 = mx3 = INT_MIN;
        mn = mn2 = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(nums[i] >= mx) {
                mx3 = mx2;
                mx2 = mx;
                mx = nums[i];
            }
            else if(nums[i] >= mx2) {
                mx3 = mx2;
                mx2 = nums[i];
            }
            else if(nums[i] >= mx3) {
                mx3 = nums[i];
            }
            if(nums[i] <= mn) {
                mn2 = mn;
                mn = nums[i];
            }
            else if(nums[i] <= mn2) {
                mn2 = nums[i];
            }
        }
        return max(mx*mx2*mx3, mx*mn*mn2);
    }
};
