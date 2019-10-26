//Problem - 973
// https://leetcode.com/problems/k-closest-points-to-origin/

// O(nlogk) time complexity and O(k) space complexity sol

class Solution {
public:
    double distance(vector <int> v) {
        return sqrt(pow(v[0], 2) + pow(v[1], 2));
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& v, int K) {
        
        priority_queue <pair<double, vector<int>>> pq;
        for(int i = 0; i < v.size(); i++) {
            pq.push({distance(v[i]), v[i]});
            if(pq.size()>K) pq.pop();
        }
        vector <vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};