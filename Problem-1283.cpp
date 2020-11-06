// Problem - 1283

// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

// O(nlog(max(nums)) time complexity and O(1) space complexity solution

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int sum = 0;
        int l = 1, h = *max_element(nums.begin(), nums.end());
        while(l < h) {
            int mid = (h-l)/2 + l;
            sum = 0;
            for(int val : nums) {
                sum += ceil(double(val)/mid);
            }
            if(sum > threshold) {
                l = mid+1;
            }
            else {
                h = mid;
            }
        }
        return h;
    }
};
