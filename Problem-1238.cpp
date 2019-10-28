//Problem - 1238
// https://leetcode.com/problems/circular-permutation-in-binary-representation/

// O(n) time complexity and O(n) space complexity sol

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int sz = pow(2, n);
        vector <int> temp, ans;
        for(int i = 0; i < sz; i++) {
            int x = i ^ (i >> 1);
            temp.push_back(x);
        }
        int i = 0;
        for(i = 0; i < sz; i++) {
            if(temp[i] == start)
                break;
        }
        for(int j = i; j < sz; j++)
            ans.push_back(temp[j]);
        for(int j = 0; j < i; j++)
            ans.push_back(temp[j]);
        return ans;
    }
};