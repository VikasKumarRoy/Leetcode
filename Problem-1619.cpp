// Problem - 1619

// https://leetcode.com/problems/mean-of-array-after-removing-some-elements/

// O(nlogn) time complexity and O(1) space complexity solution

class Solution {
public:
    double trimMean(vector<int>& arr) {
        double sum = 0;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int d = 0.05 * n;
        for(int i = d; i < n-d; i++) {
            sum += arr[i];
        }
        return sum/(n-2*d);
    }
};
