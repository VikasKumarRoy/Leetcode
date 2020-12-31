// Problem - 833

// https://leetcode.com/problems/find-and-replace-in-string/

// O(n*S) time complexity and O(n) space complexity solution

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n = indexes.size();
        vector <pair <int, int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({indexes[i], i});
        }
        sort(v.rbegin(), v.rend());
        for(int i = 0; i < n; i++) {
            int ind = v[i].first;
            string s = sources[v[i].second];
            string t = targets[v[i].second];
            string sub = S.substr(ind, s.length());
            if(sub == s) {
                S = S.substr(0, ind) + t + S.substr(ind+s.length());
            }
        }
        return S;
    }
};
