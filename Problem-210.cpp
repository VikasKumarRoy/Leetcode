// Problem - 210

// https://leetcode.com/problems/course-schedule-ii/

// O(V + E) time complexity and O(V) space complexity solution using topological sort

class Solution {
public:
    bool dfs(vector <int> graph[], vector <bool> &visited, vector <bool> &track, stack <int> &s, int v) {
        if(visited[v] && track[v])
            return false;
        else if(visited[v])
            return true;
        visited[v] = true;
        track[v] = true;
        bool flag = true;
        for(int u : graph[v]) {
            flag &= dfs(graph, visited, track, s, u);
        }
        track[v] = false;
        s.push(v);
        return flag;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> graph[numCourses];
        vector <bool> visited(numCourses, false), track(numCourses, false);
        vector <int> ans;
        for(auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }
        stack <int> s;
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                if(!dfs(graph, visited, track, s, i))
                    return {};
            }
        }
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        if(ans.size() == numCourses)
            return ans;
        return {};
    }
};
