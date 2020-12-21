// Problem - 410

// https://leetcode.com/problems/split-array-largest-sum/

// O(nlogn) time complexity and O(1) space complexity solution

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int h = accumulate(nums.begin(), nums.end(), 0);
        int l = *max_element(nums.begin(), nums.end());
        while(l < h) {
            int mid = (h-l)/2 + l;
            if(canBeSplit(nums, m, mid)) {
                h = mid;
            }
            else {
                l = mid+1;
            }
        }
        return l;
    }
    
    bool canBeSplit(vector <int>& nums, int m, int maxSum) {
        int parts = 1;
        int sum = 0;
        for(int num : nums) {
            sum += num;
            if(sum > maxSum) {
                parts++;
                sum = num;
            }
        }
        return parts <= m;
    }
};
