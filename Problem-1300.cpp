// Problem - 1300

// https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/

// O(nlogn) time complexity and O(n) space complexity solution

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int mn = arr[0], mx = arr[0];
        int n = arr.size();
        vector <int> preSum(n+1, 0);
        int ans = 0;
        for(int i = 1; i < n+1; i++) {
            preSum[i] = preSum[i-1] + arr[i-1];
            mn = min(mn, arr[i-1]);
            mx = max(mx, arr[i-1]);
        }
        int sum = 0, diff = INT_MAX;
        for(int i = 0; i <= mx; i++) {
            auto pos = lower_bound(arr.begin(), arr.end(), i);
            sum = (arr.end()-pos)*i + preSum[pos-arr.begin()];
            if(abs(sum-target) < diff) {
                diff = abs(sum-target);
                ans = i;
            }
        }
        return ans;
    }
};