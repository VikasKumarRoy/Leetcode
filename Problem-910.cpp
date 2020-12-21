// Problem - 910

// https://leetcode.com/problems/smallest-range-ii/

// O(nlogn) time complexity and O(1) space complexity solution

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int n = A.size();
        sort(A.begin(), A.end());
        int ans = A[n-1] - A[0];
        for(int i = 0; i < n-1; i++) {
            int mx = max(A[i]+K, A[n-1]-K);
            int mn = min(A[i+1]-K, A[0]+K);
            ans = min(ans, mx-mn);
        }
        return ans;
    }
};
