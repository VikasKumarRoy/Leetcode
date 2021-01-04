// Problem - 692

// https://leetcode.com/problems/most-common-word/

// O(nlogk) time complexity and O(n) space complexity solution using max heap and custom comparitor class

class Solution {
public:
    class CustomSort{
        public:
        bool operator()(pair <int, string> & p1, pair <int, string>& p2) {
            if(p1.first == p2.first) {
                return p1.second > p2.second;
            }
            return p1.first < p2.first;
        }   
    };
    unordered_map <string, int> um;
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        for(string s : words) {
            um[s]++;
        }
        priority_queue <pair <int, string>, vector <pair <int, string>>, CustomSort> pq;
        for(auto p : um) {
            pq.push({p.second, p.first});
        }
        vector <string> ans;
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
