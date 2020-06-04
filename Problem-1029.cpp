/ Problem - 1029

// https://leetcode.com/problems/two-city-scheduling/

// O(nlogn) time complexity and O(1) space complexity solution

class Solution {
public:
    static bool myRule(const vector <int> &v1, const vector <int> &v2) {
        return (v1[0] - v1[1] < v2[0] - v2[1]);
    }
    
    int twoCitySchedCost(vector<vector<int>>& cs) {
        sort(cs.begin(), cs.end(), myRule);
        int ans = 0;
        for (int i = 0; i < cs.size(); i++){
            ans += i < cs.size()/2 ? cs[i][0] : cs[i][1];
        }
        return ans;
    }
};
