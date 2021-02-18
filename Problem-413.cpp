// Problem - 413

// https://leetcode.com/problems/arithmetic-slices/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n < 3)
            return 0;
        int ans = 0, i = 1, d = A[1] - A[0], len = 1;
        while(i < n) {
            if(A[i] - A[i-1] == d) {
                len++;
                ans += (max(0, len-2));
            }
            else {
                len = 2;
                d = A[i] - A[i-1];
            }
            i++;
        }
        return ans;
    }
};
