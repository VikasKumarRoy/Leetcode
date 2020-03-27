//Problem - 118

// https://leetcode.com/problems/pascals-triangle/

// Time Complexity O(n^2) and O(n^2) space complexity solution

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector <int>> v;
        if(numRows == 0)
            return v;
        if(numRows == 1) {
            v.push_back({1});
            return v;
        }
        for(int i = 2; i <= numRows; i++) {
            vector <int> arr(i, 1);
            for(int j = 1; j < i-1; j++)
                arr[j] = v[i-2][j-1] + v[i-2][j];
            v.push_back(arr);
        }
        return v;
    }
};
