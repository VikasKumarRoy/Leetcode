// Problem - 1341

// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

// O(n*m + n*logk) time complexity and O(k) space complexity solution using bfs

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector <int> ans;
        priority_queue <pair<int, int>> pq;
        for(int i = 0; i < mat.size(); i++) {
            int val = 0;
            for(int j = 0; j < mat[i].size(); j++) {
                if(mat[i][j])
                    val++;
                else
                    break;
            }
            if(pq.size() < k)
                pq.push({val, i});
            else {
                auto p = pq.top();
                if(p.first > val) {
                    pq.push({val, i});
                    if(pq.size() > k)
                        pq.pop();
                }
            }
        }
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return vector <int> (ans.rbegin(), ans.rend());
    }
};