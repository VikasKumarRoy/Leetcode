// Problem - 1550

// https://leetcode.com/problems/three-consecutive-odds/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int ctr = 0;
        for(int val : arr) {
            if(val&1)
                ctr++;
            else
                ctr = 0;
            if(ctr == 3)
                return true;
        }
        return false;
    }
};
