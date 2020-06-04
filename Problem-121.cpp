// Problem  - 121

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Passes all test cases O(n) time complexity and constant space 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        int min_ind = 0;
        int profit = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] - prices[min_ind] > 0)
                profit = max(profit, prices[i] - prices[min_ind]);
            if(prices[i] < prices[min_ind])
                min_ind = i;
        }
        return profit;
    }
};
