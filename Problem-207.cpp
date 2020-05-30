// Problem - 207

// https://leetcode.com/problems/course-schedule/

// O(N + V) time complexity and O(N + V) space complexity solution using dfs find cycle

class Solution {
public:
    bool dfs(vector <int> graph[], vector <int> &visited, vector <int> &track, int v) {
        if(visited[v] && track[v])
            return false;
        if(visited[v])
            return true;
        visited[v] = true;
        track[v] = true;
        for(auto i : graph[v])
            if(!dfs(graph, visited, track, i))
                return false;
        track[v] = false;
        return true;        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> graph[numCourses];
        vector <int> visited(numCourses), track(numCourses);
        for(auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                if(!dfs(graph, visited, track, i))
                    return false;
            }
        }
        return true;
    }
};
