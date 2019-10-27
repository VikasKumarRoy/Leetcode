//Problem - 1237
// https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/

// O(n) time complexity and O(1) space complexity sol

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector <vector<int>> ans;
        for(int i = 1; i <= z; i++) {
            for(int j = 1; j <= z; j++) {
                int x = customfunction.f(i, j);
                if(x == z)
                    ans.push_back({i, j});
                if(x > z)
                    break;
            }
        }
        return ans;
    }
};