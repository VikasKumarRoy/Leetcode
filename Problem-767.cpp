// Problem - 767

// https://leetcode.com/problems/reorganize-string/

// O(nlogn) time complexity and O(n) space complexity solution using max-heap

class Solution {
public:
    string reorganizeString(string S) {
        unordered_map <char, int> um;
        for(char c : S) {
            um[c]++;
        }
        priority_queue <pair<int, char>> pq;
        for(auto it : um) {
            pq.push({it.second, it.first});
        }
        string ans;
        while(pq.size() >= 2) {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();
            ans += p1.second;
            ans += p2.second;
            if(p1.first > 1) {
                p1.first--;
                pq.push(p1);
            }
            if(p2.first > 1) {
                p2.first--;
                pq.push(p2);
            }
        }
        if(!pq.empty()) {
            if(pq.top().first > 1)
                return "";
            else
                ans += pq.top().second;
        }
        return ans;
    }
};

// OR O(n) time complexity by filling even postion first

