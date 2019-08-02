//Problem - 264
// https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n < 2)
            return n;
        int arr[n];
        arr[0] = 1;
        int i2 , i3, i5;
        i2 = i3 = i5 = 0;
        for(int i = 1; i < n; i++) {
            arr[i] = min(arr[i2] * 2, min(arr[i3] * 3, arr[i5] * 5));
            if(arr[i] == arr[i2] * 2)   i2++;
            if(arr[i] == arr[i3] * 3)   i3++;
            if(arr[i] == arr[i5] * 5)   i5++;
        }
        return arr[n-1];
    }
};