//Problem - 1089

// https://leetcode.com/problems/duplicate-zeros/

// O(n) time complexity and O(1) space complexity solution two pass

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int ctr = 0;
        for(int i = 0; i < arr.size(); i++)
            if(arr[i] == 0)
                ctr++;
        int i = arr.size() - 1;
        int j = arr.size() + ctr - 1;
        while(i >= 0 && j >= 0) {
            if(arr[i] != 0) {
                if(j < arr.size())
                    arr[j] = arr[i];
            }
            else {
                if(j < arr.size())
                    arr[j] = 0;
                j--;
                if(j < arr.size())
                    arr[j] = 0;
            }
            --i, --j;
        }
    }
};