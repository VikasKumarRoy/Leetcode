//Problem  - 122
// https://leetcode.com/problems/minimum-depth-of-binary-tree/

// Passes all test cases O(n) time complexity and constant space 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        int profit = 0;
        int buy = 0;   
        prices.push_back(-1);
        for(int i = 0; i < prices.size()-1; i++) {
            if(prices[i] > prices[i+1]) {
                profit += prices[i] - prices[buy];
                buy = i+1;
            }
        }
        return profit;
    }
};
   