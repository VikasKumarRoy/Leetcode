// Problem - 714

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector <int> buy(n, 0), sell(n, 0);
        buy[0] = -prices[0];
        for(int i = 1; i < n; i++) {
            buy[i] = max(buy[i-1], sell[i-1] - prices[i]);
            sell[i] = max(sell[i-1], buy[i] + prices[i] - fee);
        }
        return sell[n-1];
    }
};
