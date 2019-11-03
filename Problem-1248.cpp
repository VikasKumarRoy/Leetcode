//Problem - 1248
// https://leetcode.com/problems/count-number-of-nice-subarrays/

// O(n) time complexity and O(1) space complexity sol

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector <int> pref(nums.size());
        int ans = 0;
        for(int i = 0, odd = 0; i < nums.size(); i++) {
            pref[odd]++;
            if(nums[i] & 1)
                odd++;
            if(odd >= k)
                ans += pref[odd-k];
        }
        return ans;
    }
};