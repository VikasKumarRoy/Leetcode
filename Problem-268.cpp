//Problem - 268

// https://leetcode.com/problems/missing-number/

// O(n) time complexity and O(1) space complexity sol

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.empty())
            return 0;
        nums.push_back(0);
        int n = nums.size();
        for(int i = 0; i < n-1; i++)
            nums[nums[i]%n] += n;
        for(int i = 0; i < n; i++)
            if(nums[i]/n == 0)
                return i;
        return n;
    }
};

// Another approach with XOR

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        int x = n;
        for(int i = 0; i < n; i++)
            x ^= nums[i] ^ i;
        return x;
    }
};

