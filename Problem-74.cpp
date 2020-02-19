// Problem - 74

// https://leetcode.com/problems/search-a-2d-matrix/

// O(log(m*n)) time complexity and O(1) space complexity solution using binary search

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        if(m == 0)
            return 0;
        int l = 0, h = n-1;
        int mid = 0;
        while(l <= h) {
            mid = (l+h) / 2;
            if(matrix[mid][0] <= target && target <= matrix[mid][m-1])
                break;
            if(target < matrix[mid][0])
                h = mid-1;
            else
                l = mid+1;
        }
        int row = mid;
        l = 0, h = m-1;
        while(l <= h) {
            mid = (l+h) / 2;
            if(matrix[row][mid] == target)
                return 1;
            if(target < matrix[row][mid])
                h = mid-1;
            else
                l = mid+1;
        }
        return 0;
    }
};

// Anotehr O(log(n*m)) solution by treating 2D as 1D array

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, h = m*n-1;
        int mid = 0;
        while(l <= h) {
            mid = (l+h) / 2;
            int midVal = matrix[mid/m][mid%m];
            if(midVal == target)
                return 1;
            if(target < midVal)
                h = mid-1;
            else
                l = mid+1;
        }
        return 0;
    }
};


