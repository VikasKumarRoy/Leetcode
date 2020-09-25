// Problem - 1588

// https://leetcode.com/problems/sum-of-all-odd-length-subarrays/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += arr[i] * ceil((i+1)*(n-i)/2.0);
        }
        return ans;
    }
};
