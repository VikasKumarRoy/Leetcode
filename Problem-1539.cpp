// Problem - 1539

// https://leetcode.com/problems/kth-missing-positive-number/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int next = 1;
        int n = arr.size();
        int i = 0;
        while(i < n) {
            if(arr[i] == next) {
                next++;
            }
            else {
                if(arr[i] - next >= k)
                    return next+k-1;
                else
                    k -= arr[i]-next;
                next = arr[i]+1;
            }
            i++;
        }
        return arr[n-1]+k;
    }
};

// OR O(logn) time using binary search

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int next = 1;
        int n = arr.size();
        int i = 0;
        while(i < n) {
            if(arr[i] == next) {
                next++;
            }
            else {
                if(arr[i] - next >= k)
                    return next+k-1;
                else
                    k -= arr[i]-next;
                next = arr[i]+1;
            }
            i++;
        }
        return arr[n-1]+k;
    }
};
