//Problem  - 128
// https://leetcode.com/problems/longest-consecutive-sequence/


// O(nlogn) solution passes all test cases
class Solution {
public:
    int longestConsecutive(vector<int>& nums){
        if(nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int l_length = 1, g_length = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1])
                continue;
            if(nums[i-1]+1 == nums[i])
                l_length++;
            else {
                g_length = max(g_length, l_length);
                l_length = 1;
            }
        }
        g_length = max(g_length, l_length);
        return g_length;
    }
};

// O(n) solution using hash map
class Solution {
public:
    int longestConsecutive(vector<int>& nums){
        if(nums.size() == 0)
            return 0;
        unordered_map <int, bool> mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]] = true;
        
        int l_length = 1, g_length = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.find(nums[i]-1) == mp.end()) {
                l_length = 1;
                while(mp.find(nums[i]+l_length) != mp.end())
                    l_length++;
                g_length = max(l_length, g_length);
            }
        }
        return g_length;
    }
};