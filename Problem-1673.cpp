// Problem - 1673

// https://leetcode.com/problems/find-the-most-competitive-subsequence/

// O(n) time complexity and O(n) space complexity solution using monotonic stack

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        stack <int> s;
        vector <int> ans;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && nums[i] < s.top() && (s.size() + n-i > k))
                s.pop();
            s.push(nums[i]);
        }
        while(s.size() > k)
            s.pop();
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
