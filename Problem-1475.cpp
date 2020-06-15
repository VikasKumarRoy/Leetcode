// Problem - 1475

// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

// O(n) time complexity and O(n) space complexity solution using stack

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector <int> ans(prices.size());
        stack <pair <int, int>> s;
        s.push({prices[0], 0});
        for(int i = 1; i < prices.size(); i++) {
            while(!s.empty() && prices[i] <= s.top().first) {
                auto [val, ind] = s.top();
                s.pop();
                ans[ind] = val - prices[i];
            }
            s.push({prices[i], i});
        }
        while(!s.empty()) {
            auto [val, ind] = s.top();
            s.pop();
            ans[ind] = val;
        }
        return ans;
    }
};
