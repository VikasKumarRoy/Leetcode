//Problem - 322
// https://leetcode.com/problems/coin-change/

//Recursive Solution
class Solution {
public:
    int getMinCoins(vector <int> coins, int ind, int amount) {
        if(amount < 0)
            return INT_MAX;
        if(amount == 0)
            return 0;
        int x = INT_MAX;
        for(int i = 0; i < coins.size(); i++) {
            if(coins[i] <= amount)
                x = min(x, getMinCoins(coins, i, amount - coins[i]));
        }
        return x == INT_MAX ? INT_MAX : x + 1;
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size() == 0)
            return 0;
        int res = getMinCoins(coins, 0, amount);
        return INT_MAX == res ? -1 : res;
    }
};

//Memorization(Top Down)
class Solution {
public:
    int getMinCoins(vector <int> coins, int ind, int amount, vector <vector <int>> &dp) {
        if(amount < 0)
            return INT_MAX;
        if(amount == 0)
            return 0;
        if(dp[ind][amount] == -1) {
            int x = INT_MAX;
            for(int i = 0; i < coins.size(); i++) {
                if(coins[i] <= amount)
                    x = min(x, getMinCoins(coins, i, amount - coins[i], dp));
            }
            dp[ind][amount] = x == INT_MAX ? INT_MAX : x + 1;
        }
        return dp[ind][amount];
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size() == 0)
            return 0;
        vector <vector <int>> dp(coins.size(), vector <int> (amount+1, -1));
        int res = getMinCoins(coins, 0, amount, dp);
        return INT_MAX == res ? -1 : res;
    }
};

//Tabulation(Bottom Up) passes all tc
class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size() == 0)
            return 0;
        vector <int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < coins.size(); i++)
            for(int j = 1; j <= amount; j++) {
                if(coins[i] <= j)
                    dp[j] = min(dp[j], (dp[j-coins[i]] != INT_MAX ? 1 + dp[j-coins[i]] : INT_MAX));
            }
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};
