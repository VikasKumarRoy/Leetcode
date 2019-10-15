//Problem - 1202
// https://leetcode.com/problems/smallest-string-with-swaps/

// O(nlogn) time complexity and O(n) space complexity sol using disjoint set

class Solution {
public:
    int find(vector <int> &ds, int i) {
        if(ds[i] < 0)
            return i;
        else 
            return ds[i] = find(ds, ds[i]);
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector <int> ds(s.length(), -1);
        for(int i = 0 ; i < pairs.size(); i++){
            int j = find(ds, pairs[i][0]);
            int k = find(ds, pairs[i][1]);
            if(j != k)
                ds[j] = k;
        }
        unordered_map <int, vector <int>> m;
        for(int i = 0; i < s.length(); i++)
            m[find(ds, i)].push_back(i);
        for(auto itr : m) {
            string str = "";
            vector <int> t = itr.second;
            for(auto val : t) {
                str += s[val];
            }
            sort(str.begin(), str.end());
            for(int i = 0; i < t.size(); i++)
                s[t[i]] = str[i];
        }
        return s;
    }
};