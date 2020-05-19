// Problem - 901

// https://leetcode.com/problems/online-stock-span/

// O(1) time comlexity and O(n) space solution using stack

class StockSpanner {
public:
    stack <pair <int, int>> s;
    StockSpanner() {
    }
    
    int next(int price) {
        int ctr = 1;
        while(!s.empty() && price >= s.top().first) {
            ctr += s.top().second;
            s.pop();
        }
        s.push({price, ctr});
        return ctr;
    }
};
