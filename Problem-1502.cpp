// Problem - 1502

// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int d = arr[1] - arr[0];
        for(int i = 2; i < arr.size(); i++) {
            if(arr[i] - arr[i-1] != d)
                return false;
        }
        return true;
    }
};
