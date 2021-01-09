// Problem - 1054

// https://leetcode.com/problems/distant-barcodes/

// O(nlogn) time complexity and O(n) space complexity solution

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector <int> ans;
        unordered_map <int, int> um;
        for(int val : barcodes) {
            um[val]++;
        }
        priority_queue <pair <int, int>> pq;
        for(auto p : um) {
            pq.push({p.second, p.first});
        }
        while(pq.size() >= 2) {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();
            ans.push_back(p1.second);
            ans.push_back(p2.second);
            if(--p1.first > 0)
                pq.push(p1);
            if(--p2.first > 0)
                pq.push(p2);
        }
        if(!pq.empty())
            ans.push_back(pq.top().second);
        return ans;
    }
};
