// Problem - 132

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector <int> profit(n, 0);
        int mx = prices[n-1];
        for(int i = n-2; i >=0; i--) {
            mx = max(mx, prices[i]);
            profit[i] = max(profit[i+1], mx-prices[i]);
        }
        int mn = prices[0];
        for(int i = 1; i < n; i++) {
            mn = min(mn, prices[i]);
            profit[i] = max(profit[i-1], (i == n-1 ? 0 : profit[i+1]) + prices[i]-mn);
        }
        return profit[n-1];
    }
};
