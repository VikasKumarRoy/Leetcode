// Problem - 977

// https://leetcode.com/problems/squares-of-a-sorted-array/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i = 0, j, n = A.size();
        while(i < n && A[i] < 0)
            i++;
        j = i-1;
        vector <int> ans;
        while(j >= 0 && i < n) {
            if(A[i] <= abs(A[j]))
                ans.push_back(pow(A[i++], 2));
            else
                ans.push_back(pow(A[j--], 2));
        }
        while(i < n)
            ans.push_back(pow(A[i++], 2));
        while(j >= 0)
            ans.push_back(pow(A[j--], 2));
        return ans;
    }
};
