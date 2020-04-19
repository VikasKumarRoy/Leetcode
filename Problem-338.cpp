// Problem-338

// https://leetcode.com/problems/counting-bits/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> ans(n+1, 0);
        for(int i = 1; i <= n; i++) {
            if(i&1)
                ans[i] = ans[i-1] + 1;
            else
                ans[i] = ans[i >> 1];
        }
        return ans;
    }
};
