//Problem - 1243
// https://leetcode.com/problems/array-transformation/

// O(n*k) time complexity and O(1) space complexity sol

class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        int len = arr.size();
        int ctr;
        vector <int> temp(len);
        while(1) {
            ctr = 0;
            temp = arr;
            for(int i = 1; i < len-1; i++) {
                if(arr[i] < arr[i-1] && arr[i] < arr[i+1]) {
                    temp[i]++;
                    ctr++;
                }
                if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
                    temp[i]--;
                    ctr++;
                }
            }
            arr = temp;
            if(ctr == 0)
                return arr;
        }
    }
};