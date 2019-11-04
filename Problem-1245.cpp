//Problem - 1245

// https://leetcode.com/problems/tree-diameter/

// O(n)  time complexity for dfs and O(n) space complexity sol

class Solution {
public:
    int dia = 0;
    
    int dfs(vector <int> v[], vector <bool> visited, int curr) {
        visited[curr] = 1;
        int mx = 0, mx_2 = 0;
        for(auto i : v[curr]) {
            if(!visited[i]) {
                int d = dfs(v, visited, i);
                if(mx <= d) {
                    mx_2 = mx;
                    mx = d;
                }
                else if(d > mx_2)
                    mx_2 = d;
            }
        }
        //cout << curr << "->" << mx << " " << mx_2 << endl;
        dia = max(mx + mx_2, dia);
        return mx+1;
    }
    
    int treeDiameter(vector<vector<int>>& edges) {
        int sz = 1e4 + 1;
        vector <int> graph[sz];
        vector <bool> visited(sz, 0);
        for(auto edg : edges) {
            graph[edg[0]].push_back(edg[1]);
            graph[edg[1]].push_back(edg[0]);
        }
        dfs(graph, visited, 0);
        return dia;
    }
};
