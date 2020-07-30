// Problem - 309

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

// O(n) time complexity and O(1) space complexity solution using dp

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector <int> dp(n);
        int mn = 0;
        int last = 0;
        for(int i = 1; i < n; i++) {
            if(prices[i-1] > prices[i]) {
                mn = i;
                if(i > 1)
                    dp[i] = dp[i-1];
            }
            else {
                dp[i] = dp[i] + prices[i] - prices[mn];
                last = i;
            }
        }
        
    }
};
