// Problem - 213

// https://leetcode.com/problems/house-robber-ii/

// O(n) time complexity and O(n) space complexity solution

int rob(vector<int>& nums) {
      int n = nums.size();
      if(n == 1)
          return nums[0];
      vector <int> dp(n , 0);
      dp[0] = nums[0];
      for(int i = 1; i < n-1; i++) { 
          dp[i] = max(dp[i-1], nums[i] + (i > 1 ? dp[i-2] : 0));
      }
      vector <int> dp2(n , 0);
      dp2[1] = nums[1];
      for(int i = 2; i < n; i++) { 
          dp2[i] = max(dp2[i-1], nums[i] + (i > 2 ? dp2[i-2] : 0));
      }
      return max(dp[n-2], dp2[n-1]);
  }
  
  //            OR       in constant space
  
  int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int curr = nums[0], prev;
        for(int i = 1; i < n-1; i++) { 
            int temp = max(curr, nums[i] + (i > 1 ? prev : 0));
            prev = curr;
            curr = temp;
        }
        int ans = curr;
        curr = nums[1];
        for(int i = 2; i < n; i++) { 
            int temp = max(curr, nums[i] + (i > 2 ? prev : 0));
            prev = curr;
            curr = temp;
        }
        return max(ans, curr);
    }
