// Problem - 823

// https://leetcode.com/problems/binary-trees-with-factors/

// O(n^2) time complexity and O(1) space complexity solution where n = no. of chars

class Solution {
public:
    const int mod = 1e9 + 7;
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map <int, long> dp;
        int ans = 0;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++) {
            long ctr = 1;
            for(int j = 0; j < i; j++) {
                if(arr[i] % arr[j] == 0) {
                    ctr = (ctr + (dp[arr[j]] * dp[arr[i]/arr[j]])%mod)%mod;
                }
            }
            dp[arr[i]] = ctr;
            ans = (ans + ctr)%mod;
        }
        return ans;
    }
};
