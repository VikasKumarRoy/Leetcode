//Problem - 1244

// https://leetcode.com/problems/design-a-leaderboard/

// O(nlogk) for top() rest O(1) time complexity and O(n) space complexity sol

class Leaderboard {
public:
    unordered_map <int, int> um;
    
    Leaderboard() {
        um.clear();
    }
    
    void addScore(int playerId, int score) {
        um[playerId] += score;
    }
    
    int top(int K) {
        priority_queue <int, vector <int>, greater <int>> pq;
        int ctr = 0;
        for(auto itr : um) {
            if(ctr < K)
                pq.push(itr.second);
            else {
                if(itr.second > pq.top()) {
                    pq.pop();
                    pq.push(itr.second);
                }
            }
            ctr++;
        }
        int sum = 0;
        while(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
    
    void reset(int playerId) {
        um[playerId] = 0;
    }
};
