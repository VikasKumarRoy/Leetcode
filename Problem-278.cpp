// Problem - 278

// https://leetcode.com/problems/first-bad-version/

// O(logn) time complexity and O(1) space complexity solution

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int h = n;
        int ans = 0;
        while(l <= h) {
            int mid = (h-l)/2 + l;
            bool bad = isBadVersion(mid);
            if(bad) {
                ans = mid;
                h = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return ans;
    }
};
