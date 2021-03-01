// Problem - 895

// https://leetcode.com/problems/maximum-frequency-stack/

// O(1) time complexity and O(n) space complexity solution

class FreqStack {
public:
    unordered_map <int, int> freq;
    unordered_map <int, stack<int>> um;
    int _max;
    
    FreqStack() {
        _max = 0;
    }
    
    void push(int x) {
        freq[x]++;
        _max = max(freq[x], _max);
        um[freq[x]].push(x);
    }
    
    int pop() {
        int x = um[_max].top();
        um[_max].pop();
        freq[x]--;
        if(um[_max].empty())
            _max--;
        return x;
    }
};
