// Problem - 188

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

// O(n*k) time complexity and O(n*k) space complexity solution

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n < 2)
            return 0;
        if(k >= n/2)
            return quickSolve(prices);
        vector <vector <int>> dp(k+1, vector <int> (n, 0));
        for(int t = 1; t <= k; t++) {
            int max_so_far = INT_MIN;
            for(int i = 1; i < n; i++) {
                max_so_far = max(max_so_far, dp[t-1][i-1] - prices[i-1]);
                dp[t][i] = max(dp[t][i-1], max_so_far + prices[i]);
            }
        }
        return dp[k][n-1];
    }
    
    int quickSolve(vector <int> prices) {
        int profit = 0;
        for(int i = 1; i < prices.size(); i++) {
            profit += max(0, prices[i]-prices[i-1]);
        }
        return profit;
    }
};
