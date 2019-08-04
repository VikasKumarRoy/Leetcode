//Problem - 518
// https://leetcode.com/problems/coin-change-2//

//Recursive Solution will give TLE
class Solution {
public:
    int getMinCoins(vector <int> coins, int ind, int amount) {
        if(amount < 0 || ind >= coins.size())
            return 0;
        if(amount == 0)
            return 1;
        return getMinCoins(coins, ind, amount - coins[ind]) + getMinCoins(coins, ind+1, amount);
    }
    
    int change(int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;
        if(coins.size() == 0)
            return 0;
        return getMinCoins(coins, 0, amount);
    }
};
    
    
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size() == 0)
            return 0;
        int res = getMinCoins(coins, 0, amount);
        return INT_MAX == res ? -1 : res;
    }
};

//Memorization(Top Down) will give TLE
class Solution {
public:
    int getMinCoins(vector <int> coins, int ind, int amount, vector <vector<int>> &dp) {
        if(amount < 0 || ind >= coins.size())
            return 0;
        if(amount == 0)
            return 1;
        if(dp[ind][amount] == -1)
            dp[ind][amount] =  getMinCoins(coins, ind, amount-coins[ind], dp) + getMinCoins(coins, ind+1, amount, dp);
        return dp[ind][amount];
    }
    
    int change(int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;
        if(coins.size() == 0)
            return 0;
        vector <vector<int>> dp(coins.size()+1, vector <int> (amount+1, -1));
        return getMinCoins(coins, 0, amount, dp);
    }
};


//Tabulation(Bottom Up) passes all tc
class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;
        if(coins.size() == 0)
            return 0;
        vector <int> dp(amount+1, 0);
        dp[0] = 1;
        for(int i = 0; i < coins.size(); i++)
            for(int j = 1; j <= amount; j++)
                dp[j] += (coins[i] <= j ? dp[j - coins[i]] : 0);
        return dp[amount];
    }
};
