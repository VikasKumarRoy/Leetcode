// Problem - 1503

// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = left.size() ? *max_element(left.begin(), left.end()) : 0;
        for(int val : right) {
            ans = max(ans, n-val);
        }
        return ans;
    }
};
