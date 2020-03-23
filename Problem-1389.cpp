// Problem - 1389

// https://leetcode.com/problems/create-target-array-in-the-given-order/

// O(n^2) time complexity and O(1) space complexity solution

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector <int> ans;
        for(int i = 0; i < index.size(); i++)
            ans.insert(ans.begin() + index[i], nums[i]);
        return ans;
    }
};
