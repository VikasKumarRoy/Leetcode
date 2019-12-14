//Problem - 5126

// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int ele = 1, ctr = arr[0];
        int n = arr.size();
        for(int i = 1; i < n; i++) {
            if(arr[i] == ele)
                ctr++;
            else {
                ctr = 1;
                ele = arr[i];
            }
            if(ctr > n/4)
                return ele;
        }
        return arr[0];
    }
};