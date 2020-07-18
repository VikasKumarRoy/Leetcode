// Problem - 347

// https://leetcode.com/problems/top-k-frequent-elements/

// O(nlogk) time complexity and O(n) space complexity solution using hash map and min heap

class Solution {
public:
    typedef pair<int, int> pi;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue <pi, vector<pi>, greater<pi>> pq; 
        unordered_map <int, int> um;
        for(int val: nums)
            um[val]++;
        for(auto p: um) {
            if(pq.size() < k || pq.top().first < p.second) {
                if(pq.size() >= k)
                    pq.pop();
                pq.push({p.second, p.first});
            }
        }
        vector <int> ans;
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            ans.push_back({p.second});
        }
        return ans;
    }
};
