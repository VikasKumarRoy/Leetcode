// Problem - 1566

// https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        int ctr = 0;
        for(int i = 0; i+m < n; i++) {
            if(arr[i] != arr[i+m])
                ctr = 0;
            else if(arr[i] == arr[i+m])
                ctr++;
            if(ctr == (k-1)*m)
                return true;
        }
        return false;
    }
};
