// Problem - 1381

// https://leetcode.com/problems/design-a-stack-with-increment-operation/

// O(1) time complexity and O(maxSize) space complexity solution

class CustomStack {
public:
    stack <int> s;
    vector <int> v;
    int maxSz = 0;
    CustomStack(int maxSize) {
        maxSz = maxSize;
        v.resize(maxSize);
    }
    
    void push(int x) {
        if(s.size() < maxSz)
            s.push(x);
    }
    
    int pop() {
        if(s.empty())
            return -1;
        int pos = s.size()-1;
        int top_val = s.top() + v[pos];
        s.pop();
        if(pos > 0)
            v[pos-1] += v[pos];
        v[pos] = 0;
        return top_val;
    }
    
    void increment(int k, int val) {
        int pos = min(k, (int)s.size());
        if(pos > 0)
            v[pos-1] += val;
    }
};
