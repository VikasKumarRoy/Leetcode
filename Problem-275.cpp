// Problem - 275

// https://leetcode.com/problems/h-index-ii/

// O(logn) time complexity and O(1) space complexity solution using binary search

class Solution {
public:
    int hIndex(vector<int>& cit) {
        int n = cit.size();
        if(n == 0)
            return 0;
        int ans = 0;
        int l = 0, h = n-1;
        while(l <= h) {
            int mid = l + (h-l)/2;
            if(n - mid <= cit[mid]) {
                ans = max(ans, n-mid);
                h = mid-1;
            }
            else
                l = mid+1;
        }
        return ans;
    }
};
