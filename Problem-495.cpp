// Problem - 495

// https://leetcode.com/problems/teemo-attacking/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        if(timeSeries.size() == 0)
            return 0;
        for(int i = 1; i < timeSeries.size(); i++) {
            if(timeSeries[i] - timeSeries[i-1] + 1 <= duration) {
                ans += timeSeries[i] - timeSeries[i-1];
            }
            else
                ans += duration;
        }
        return ans + duration;
    }
};
