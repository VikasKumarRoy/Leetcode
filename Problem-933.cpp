// Problem - 933

// https://leetcode.com/problems/number-of-recent-calls/

// O(n) time complexity and O(n) space complexity solution using queue

class RecentCounter {
public:
    queue <long> q;
    
    RecentCounter() {
        while(!q.empty())   q.pop();
    }
    
    int ping(int t) {
        q.push(t);
        while(!q.empty() && t-3000 > q.front())
            q.pop();
        return q.size();
    }
};
