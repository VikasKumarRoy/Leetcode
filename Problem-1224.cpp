//Problem - 1224
// https://leetcode.com/problems/maximum-equal-frequency/

// O(n) time complexity and O(n) space complexity sol

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int ans = 1;
        unordered_map <int, int> freq;
        unordered_map <int, int> count;
        int mx = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(count[freq[nums[i]]] == 0) { 
                freq[nums[i]]++;
                count[freq[nums[i]]]++;
            }
            else {
                count[freq[nums[i]]]--;
                freq[nums[i]]++;
                count[freq[nums[i]]]++;
            }
            mx = max(mx, freq[nums[i]]);
            if(mx * count[mx] == i || (mx-1) * (count[mx-1] + 1) == i || mx == 1)
                ans = i+1;
        }
        return ans;
    }
};