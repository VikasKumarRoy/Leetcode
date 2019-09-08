//Problem - 155
// https://leetcode.com/problems/min-stack/

// O(1) operations on stack 

class MinStack {
public:
    stack <long long> s;
    long long mn = 0;
    
    void push(long long x) {
        if(s.empty())
            s.push(x), mn = x;
        else if(x >= mn)
            s.push(x);
        else {
            s.push(2*x - mn);
            mn = x;
        }
    }
    
    void pop() {
        if(s.top() > mn)
            s.pop();
        else {
            mn = 2*mn - s.top();
            s.pop();
        }
    }
    
    int top() {
        if(s.top() > mn)
            return s.top();
        else
            return mn;
    }
    
    int getMin() {
        return mn;
    }
};