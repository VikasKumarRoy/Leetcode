//Problem - 1177
// https://leetcode.com/problems/can-make-palindrome-from-substring/

// O(s.length() + queries.length()) comlexity using presum computation
// O(s.lenght()) space complexity 

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector <vector <int>> pre_sum(26, vector <int> (s.size(), 0));
        vector <bool> ans;
        for(int i = 0; i < s.length(); i++) {
            for(int j = 0; j < 26; j++)
                pre_sum[j][i] += i > 0 ? pre_sum[j][i-1] : 0;
            pre_sum[s[i] - 'a'][i]++;
        }
        for(auto q : queries) {
            int sum = 0;
            for(int j = 0; j < 26; j++) {
                int t = pre_sum[j][q[1]] - (q[0] == 0 ? 0 : pre_sum[j][q[0]-1]);
                if(t & 1)
                    sum ++;
            }
            ans.push_back(sum/2 <= q[2]);
        }
        return ans;
    }
};
   