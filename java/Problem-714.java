// Problem - 714

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

// O(n) time complexity and O(n) space complexity solution

class Solution {
    public int maxProfit(int[] prices, int fee) {
        int n = prices.length;
        int buy[] = new int[n], sell[] = new int[n];
        buy[0] = -prices[0];
        for(int i = 1; i < n; i++) {
            buy[i] = Math.max(buy[i-1], sell[i-1] - prices[i]);
            sell[i] = Math.max(sell[i-1], buy[i] + prices[i] - fee);
        }
        return sell[n-1];
    }
}
