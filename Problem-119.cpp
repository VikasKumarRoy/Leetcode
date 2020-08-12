// Problem - 119

// https://leetcode.com/problems/pascals-triangle-ii/

// O(n*n) time complexity and O(n) space complexity solution

class Solution {
public:
    vector<int> getRow(int k) {
        if(k == 0)
            return {1};
        vector <int> ans(k+1), temp;
        ans[0] = ans[1] = 1;
        int n = 2;
        for(int i = 2; i < k+1; i++) {
            temp = ans;
            for(int j = 1; j < n; j++) {
                ans[j] = temp[j-1] + temp[j];
            }
            ans[n] = 1;
            n++;
        }
        return ans;
    }
};
