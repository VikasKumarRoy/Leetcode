// Problem - 835

// https://leetcode.com/problems/image-overlap/

// O(n^4) time complexity and O(n^2) space complexity solution

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size(), m = A[0].size();
        int ans = 0;
        vector <pair<int, int>> a, b;
        map <pair<int, int>, int> um;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j])
                    a.push_back({i, j});
                if(B[i][j])
                    b.push_back({i, j});
            }
        }
        for(int i = 0; i < a.size(); i++) {
            for(int j = 0; j < b.size(); j++) {
                auto d = make_pair(a[i].first - b[j].first, a[i].second - b[j].second);
                um[d]++;
                ans = max(ans, um[d]);
            }
        }
        return ans;
    }
};
