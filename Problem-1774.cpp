// Problem - 1774

// https://leetcode.com/problems/closest-dessert-cost/

// O(n * 3^m) time complexity and O(m) space complexity solution

class Solution {
public:
    int mn, ans;
    
    void dfs(int ind, vector<int>& baseCosts, int total, int sum) {
        if(abs(total-sum) <= mn) {
            if(abs(total-sum) == mn)
                ans = min(ans, sum);
            else
                ans = sum;
            mn = abs(total-sum);
        }
        if(ind == baseCosts.size())
            return;
        dfs(ind+1, baseCosts, total, sum+baseCosts[ind]);
        dfs(ind+1, baseCosts, total, 2*baseCosts[ind] + sum);
        dfs(ind+1, baseCosts, total, sum);
    }
    
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        mn = INT_MAX, ans = INT_MAX;
        for(int base : baseCosts) {
            dfs(0, toppingCosts, target, base);
        }
        return ans;
    }
};
