//Problem - 89
// https://leetcode.com/problems/gray-code/

// O(2^n) time complexity and O(2^n) space complexity sol

class Solution {
public:
    vector<int> grayCode(int n) {
        vector <int> ans;
        ans.push_back(0);
        for(int i = 0; i < n; i++)
            for(int j = ans.size()-1; j >= 0; j--)
                ans.push_back(ans[j] | 1 << i);
        return ans;
    }
};