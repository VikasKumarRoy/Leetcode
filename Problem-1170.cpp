//Problem - 1170
// https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/

// Passes all test cases O(nlogn) time complexity

class Solution {
public:
    int fun(string s) {
        map <char, int> m;
        for(char c : s)
            m[c]++;
        return m.begin()->second;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector <int> ans(queries.size());
        multiset <int> st;
        for(auto s : words) {
            if(s.length())
                st.insert(fun(s));
        }
        for(int i = 0; i < queries.size(); i++) {
            int num = fun(queries[i]);
            ans[i] = distance(st.upper_bound(num), st.end());
        }
        return ans;
    }
};
   