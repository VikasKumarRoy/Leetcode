// Problem - 1652

// https://leetcode.com/problems/defuse-the-bomb/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector <int> ans(n, 0);
        if(k == 0)
            return ans;
        int i = k > 0 ? 1 : n-abs(k);
        int j = i, sum = 0;
        k = abs(k);
        while(k--)
            sum += code[(j++)%n];
        for(int k = 0; k < n; k++) {
            ans[k] = sum;
            sum += (code[j++%n] - code[i++%n]);
        }
        return ans;
    }
};
