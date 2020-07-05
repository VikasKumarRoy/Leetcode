// Problem - 1502

// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        if (n < 3)
            return true;
        int mx = *max_element(arr.begin(), arr.end());
        int mn = *min_element(arr.begin(), arr.end());
        if((mx-mn)%(n-1) != 0)
            return false;
        int d = (mx-mn)/(n-1);
        int i = 0;
        while(i < arr.size()) {
            if(arr[i] == i*d+mn)
                i++;
            else if((arr[i]-mn)%d != 0)
                return false;
            else {
                int pos = (arr[i]-mn)/d;
                if(pos < i)
                    return false;
                swap(arr[i], arr[pos]);
            }
        }
        return true;
    }
};

// OR O(nlogn) solution


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
