//Problem  - 55
// https://leetcode.com/problems/jump-game/


// Recursive soltion O(2^n)
class Solution {
public:
    bool fun(int ind, vector <int> &nums, int n) {
        if(ind >= n-1)
            return true;
        bool temp = false;
        for(int i = ind+1; i <= ind+nums[ind]; i++) {
            if(i >= n)
                break;
            temp = temp | fun(i, nums, n);
        }
        return temp;
    }
    
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0 || (nums[0] == 0 && nums.size() > 1))
            return false;
        if(nums.size() == 1)
            return true;
        return fun(0, nums, nums.size());
    }
};

// Top Down O(n^2)
class Solution {
public:
    bool fun(int ind, vector <int> &nums, int n, vector <int> &dp) {
        if(ind >= n-1)
            return true;
        if(dp[ind] == -1) {
            bool temp = false;
            for(int i = ind+1; i <= ind+nums[ind]; i++) {
                if(i >= n)
                    break;
                temp = temp | fun(i, nums, n, dp);
            }
            dp[ind] = temp ? 1 : 0;
        }
        return dp[ind] == 1 ? true : false;
    }
    
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0 || (nums[0] == 0 && nums.size() > 1))
            return false;
        if(nums.size() == 1)
            return true;
        vector <int> dp(nums.size(), -1); 
        return fun(0, nums, nums.size(), dp);
    }
};

// Bottom Up O(n^2)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0 || (nums[0] == 0 && nums.size() > 1))
            return false;
        if(nums.size() == 1)
            return true;
        vector <int> dp(nums.size(), INT_MAX); 
        dp[0] = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j <= i + nums[i]; j++) {
                if(j > nums.size()-1)
                    break;
                dp[j] = min(dp[j], dp[i] == INT_MAX ? INT_MAX : dp[i] + 1);
            }
        }
        return (dp[nums.size()-1] == INT_MAX ? 0 : 1 );
    }
};

// Greedy approach O(n)
class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0 || (nums[0] == 0 && nums.size() > 1))
            return false;
        if(nums.size() == 1)
            return true;
        int lastInd = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(i + nums[i] >= lastInd)
                lastInd = i;
        }
        return lastInd == 0;
    }
};