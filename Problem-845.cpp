// Problem - 845

// https://leetcode.com/problems/longest-mountain-in-array/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int inc, dec, ans;
        inc = dec = ans = 0;
        for(int i = 1; i < A.size(); i++) {
            if(A[i] > A[i-1]) {
                if(dec > 0){
                    dec = 0;
                    inc = 1;
                }
                else
                    inc++;
            }
            else if(A[i] < A[i-1])
                dec++;
            else
                inc = dec = 0;
            if(inc && dec)
                ans = max(inc + dec + 1, ans);
        }
        return ans;
    }
};
