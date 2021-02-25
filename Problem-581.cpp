// Problem - 581

// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        vector <bool> left(n), right(n);
        int mn = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] <= mn) {
                mn = nums[i];
            }
            else
                left[i] = 1;
        }
        int mx = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] >= mx) {
                mx = nums[i];
            }
            else
                right[i] = 1;
        }
        int i = 0, j = n-1;
        while(i < n && left[i] == 0)
            i++;
        while(j > i && right[j] == 0)
            j--;
        if(i >= j)
            return 0;
        return j-i+1;
    }
};
