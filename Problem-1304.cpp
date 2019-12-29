// Problem - 1304

// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    vector<int> sumZero(int n) {
        vector <int> ans;
        for(int i = 1; i <= n/2; i++) {
            ans.push_back(i);
            ans.push_back(-1 * i);
        }
        if(n & 1)
            ans.push_back(0);
        return ans;
    }
};