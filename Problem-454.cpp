//Problem - 454
// https://leetcode.com/problems/4sum-ii/

// Time Complexity O(n^2) and O(n^2) space complexity

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map <int, int> m;
        int ans = 0;
        for(int val1 : A)
            for(int val2 : B)
                m[val1 + val2]++;
        for(int val1 : C)
            for(int val2 : D) {
                if(m.find(-1 * (val1 + val2)) != m.end())
                    ans += m[-1 * (val1 + val2)];
            }
        return ans;
    }
};

