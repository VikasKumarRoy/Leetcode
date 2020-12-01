// Problem - 218

// https://leetcode.com/problems/the-skyline-problem/

// O(nlogn) time complexity and O(n) space complexity solution usign max heap

class Solution {
public:
    
    bool static myComp(const pair <int, pair<int, int>>& a, const pair <int, pair<int, int>>& b) {
        if(a.first == b.first) {
            return a.second.first > b.second.first;
        }
        return a.first < b.first;
    }
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector <vector <int>> ans;
        priority_queue <pair<int, int>> pq;
        vector <pair <int, pair<int, int>>> pts;
        for(auto v : buildings) {
            pts.push_back({v[0], {v[2], v[1]}});
            pts.push_back({v[1], {-v[2], v[1]}});
        }
        sort(pts.begin(), pts.end(), myComp);
        pq.push({0, INT_MAX});
        for(int i = 0; i < pts.size(); i++) {
            int x = pts[i].first;
            int h = pts[i].second.first;
            if(h >= 0) {
                int end = pts[i].second.second;
                if(h > pq.top().first) {
                    ans.push_back({x, h});
                }
                pq.push({h, end});
            }
            else {
                h = -h;
                if(pq.top().first == h) {
                    while(!pq.empty() && pq.top().second <= x)
                        pq.pop();
                    if(ans.back()[1] != pq.top().first)
                        ans.push_back({x, pq.top().first});
                }
            }
        }
        return ans;
    }
};
