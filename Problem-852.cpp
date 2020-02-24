// Problem - 852

// Peak Index in a Mountain Array

// O(logn) time complexity and O(1) space complexity solution

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0, mid = 0, h = A.size()-1;
        while(l <= h) {
            mid = (l + h) / 2;
            if(A[mid] > A[mid+1] && A[mid] > A[mid-1])
                return mid;
            else if(A[mid-1] < A[mid] && A[mid] < A[mid+1])
                l = mid+1;
            else
                h = mid-1;
        }
        return -1;
    }
};