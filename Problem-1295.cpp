// Problem - 1295

// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int val : nums) {
            string s = to_string(val);
            if(!(s.length() & 1))
                ans++;
        }
        return ans;
    }
};