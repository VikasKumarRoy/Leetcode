// Problem - 1300

// https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/

// O(nlogn) time complexity and O(n) space complexity solution using binary search

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int mx = arr[0];
        int n = arr.size();
        vector <int> preSum(n+1, 0);
        int ans = mx;
        for(int i = 1; i < n+1; i++) {
            preSum[i] = preSum[i-1] + arr[i-1];
            mx = max(mx, arr[i-1]);
        }
        int sum = 0, diff = mx;
        int l = 0, h = mx;
        while(l <= h) {
            int mid = (l + h)/2;
            auto pos = lower_bound(arr.begin(), arr.end(), mid);
            sum = (arr.end()-pos)*mid + preSum[pos-arr.begin()];
            if(abs(sum-target) < diff) {
                diff = abs(sum-target);
                ans = mid;               
            }
            else if(abs(sum-target) == diff)
                ans = min(ans, mid);
            if(sum > target)
                h = mid-1;
            else
                l = mid+1;
        }
        return ans;
    }
};