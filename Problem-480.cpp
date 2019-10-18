//Problem - 480
// https://leetcode.com/problems/sliding-window-median/

// O(nlogk) time complexity and O(n) space complexity sol

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        double median = 0;
        multiset <int> s(nums.begin(), nums.begin() + k);
        auto mid = next(s.begin(), k / 2);
        vector <double> ans;
        for (int i=k; ; i++) {
            if(k & 1)
                ans.push_back(double(*mid));
            else
                ans.push_back((double(*mid) + *prev(mid)) / 2);
            
            if (i == nums.size())
                return ans;

            s.insert(nums[i]);
            if (nums[i] < *mid)
                mid--;

            if (nums[i-k] <= *mid)
                mid++;
            s.erase(s.find(nums[i-k]));
        }

    }
};