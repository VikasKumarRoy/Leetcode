// Problem - 399

// https://leetcode.com/problems/evaluate-division/

// O(q*n^2) time complexity and O(n) space complexity solution

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map <string, vector <pair<string, double>>> um;
        vector <double> ans;
        for(int i = 0; i < equations.size(); i++) {
            um[equations[i][0]].push_back({equations[i][1], values[i]});
            um[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        for(auto q : queries) {
            if(q[0] == q[1] && um.count(q[0])) { 
                ans.push_back(1);
                continue;
            }
            stack <pair<string, double>> s;
            unordered_set <string> visited;
            s.push({q[0], 1});
            visited.insert(q[0]);
            double path = -1;
            while(!s.empty() && !visited.count(q[1])) {
                string u = s.top().first;
                double val = s.top().second;
                s.pop();
                for(auto it : um[u]) {
                    if(!visited.count(it.first)) {
                        visited.insert(it.first);
                        if(it.first == q[1])
                            path = val * it.second;
                        s.push({it.first, it.second*val});
                    }
                }
            }
            ans.push_back(path);
        }
        return ans;
    }
};
