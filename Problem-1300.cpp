// Problem - 1300

// https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/

// O(nlogn) time complexity and O(n) space complexity solution

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int mn = arr[0], mx = arr[0];
        int n = arr.size();
        vector <int> preSum(n, 0);
        preSum[0] = arr[0];
        int ans = 0;
        for(int i = 1; i < n; i++) {
            preSum[i] = presum[i-1] + arr[i];
            mn = min(mn, arr[i]);
            mx = max(mx, arr[i]);
        }
        for(int i = mn, i <= mx; i++) {
            auto pos = lower_bound(arr.begin(), arr.end(), i);
            
        }
        return ans;
    }
};