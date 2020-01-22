// Problem - 1313

// https://leetcode.com/problems/decompress-run-length-encoded-list/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector <int> ans;
        for(int i = 0; i < nums.size(); i += 2) {
            int a = nums[i], b = nums[i+1];
            while(a--)
                ans.push_back(b);
        }
        return ans;
    }
};