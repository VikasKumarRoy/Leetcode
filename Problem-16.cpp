//Problem - 16
// https://leetcode.com/problems/3sum-closest/

// Time Complexity O(n) and O(1) space complexity

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = INT_MAX;
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            int st = i+1;
            int en = n-1;
            while(st < en) {
                int sum = nums[i] + nums[st] + nums[en]; 
                if(sum > target)
                    en--;
                else if(sum < target) 
                    st++;
                else
                    return sum;
                if(abs(sum - target) < closest) {
                    closest = abs(sum-target);
                    ans = sum;
                }
            }
        }
        return ans;
    }
};


