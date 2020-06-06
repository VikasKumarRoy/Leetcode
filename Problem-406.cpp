// Problem - 406

// https://leetcode.com/problems/queue-reconstruction-by-height/

// O(n^2) time complexity and O(n) space complexity solution

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        map <int, vector <int>> m;
        vector <vector <int>> ans;
        for(auto v: people) {
            m[v[1]].push_back(v[0]);
        }
        for(auto it = m.begin(); it != m.end(); it++){
            sort(it->second.begin(),it->second.end());
        }
        for(auto p: m) {
            for(auto val: p.second) {
                int ctr = p.first;
                int pos = 0;
                while(pos < ans.size()) {
                    if(val <= ans[pos][0])
                        ctr--;
                    if(ctr < 0)
                        break;
                    pos++;
                }
                ans.insert(ans.begin() + pos, {val, p.first});
            }
        }
        return ans;
    }
};
