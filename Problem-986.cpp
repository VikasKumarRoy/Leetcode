// Problem - 986

// https://leetcode.com/problems/interval-list-intersections/

// O(n+m) time complexity and O(1) space solution using two pointers (like merge sort)

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector <vector<int>> ans;
        int i = 0, j = 0;
        while(i < A.size() && j < B.size()) {
            if(A[i][0] > B[j][1])
                j++;
            else if(B[j][0] > A[i][1])
                i++;
            else {
                ans.push_back({(max(A[i][0], B[j][0])), (min(A[i][1], B[j][1]))});
                if(A[i][1] > B[j][1])
                    j++;
                else
                    i++;
            }
        }
        return ans;
    }
};
