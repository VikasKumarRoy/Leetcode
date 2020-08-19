// Problem - 967

// https://leetcode.com/problems/numbers-with-same-consecutive-differences/

// O(2^n) time complexity and O(n) space complexity solution using dfs

class Solution {
public:
    void dfs(vector <int> &ans, int n, int k, string s) {
        if(s.length() == n) {
            ans.push_back(stoi(s));
            return;
        }
        int last = s[s.length()-1] - '0';
        if(last - k >= 0)
            dfs(ans, n, k, s+to_string(last-k));
        if(last + k < 10 && k != 0)
            dfs(ans, n, k, s+to_string(last+k));
    }
    
    vector<int> numsSameConsecDiff(int N, int K) {
        vector <int> ans;
        if(N == 1)
            ans.push_back(0);
        for(int i = 1; i < 10; i++)
            dfs(ans, N, K, to_string(i));
        return ans;
    }
};
