//Problem - 922

// https://leetcode.com/problems/sort-array-by-parity-ii/

// O(n) time complexity and O(1) space complexity sol

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int odd = 1;
        for(int i = 0; i < A.size(); i += 2) {
            if(A[i] & 1) {
                swap(A[i], A[odd]);
                odd += 2;
                i -= 2;
            }
        }
        return A;
    }
};