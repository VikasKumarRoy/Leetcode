// Problem - 941

// https://leetcode.com/problems/valid-mountain-array/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3 || arr[0] >= arr[1])
            return false;
        bool dip = false;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] == arr[i-1])
                return false;
            else if(arr[i] < arr[i-1]) {
                dip = true;
            }
            else if(arr[i] > arr[i-1] && dip)
                return false;
        }
        return dip;
    }
};
