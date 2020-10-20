// Problem - 1007

// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int ans = n+1;
        int a = 0, b = 0;
        for(int i = 0; i < n; i++) {
            if(A[0] != A[i] && A[0] != B[i])
                break;
            if(A[i] != A[0]) {
                a++;
            }
            if(B[i] != A[0]) {
                b++;
            }
            if(i == n-1)
                ans = min({ans, a, b});
        }
        a = b = 0;
        for(int i = 0; i < n; i++) {
            if(B[0] != A[i] && B[0] != B[i])
                break;
            if(A[i] != B[0]) {
                a++;
            }
            if(B[i] != B[0]) {
                b++;
            }
            if(i == n-1)
                ans = min({ans, a, b});
        }
        return ans == n+1 ? -1 : ans;
    }
};
