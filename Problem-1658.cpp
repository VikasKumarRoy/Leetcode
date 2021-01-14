// Problem - 1658

// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/solution/

// O(n) time complexity and O(1) space complexity solution using sliding window

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), ans = -1, sum = 0;
        int i = 0, j = 0;
        x = accumulate(nums.begin(), nums.end(), 0) - x;
        if(x < 0)
            return -1;
        if(x == 0)
            return n;
        while(j < n) {
            while(sum < x && j < n) {
                sum += nums[j++];
                if(sum == x)
                    ans = max(ans, j-i);
            }
            while(sum >= x && i < j) {
                sum -= nums[i++];
                if(sum == x)
                    ans = max(ans, j-i);
            }
        }
        return ans == -1 ? -1 : n-ans;
    }
};

// OR O(n) time complexity and O(n) space complexity solution using hashmap can handle -ve as well

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), ans = -1, sum = 0;
        x = accumulate(nums.begin(), nums.end(), 0) - x;
        if(x < 0)
            return -1;
        if(x == 0)
            return n;
        unordered_map <int, int> um;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum == x)
                ans = i+1;
            if(!um.count(sum))
                um[sum] = i;
            if(um.count(sum-x)) {
                ans = max(ans, i-um[sum-x]);
            }
        }
        return ans == -1 ? -1 : n-ans;
    }
};
