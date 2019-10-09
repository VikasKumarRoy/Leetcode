//Problem - 232
// https://leetcode.com/problems/implement-queue-using-stacks/

// O(1) time complexity using two stacks

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack <int> s1, s2;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(s2.empty()) {
            if(s1.empty())
                return -1;
            else {
                while(!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
                int a = s2.top();
                s2.pop();
                return a;
            }
        }
        int a = s2.top();
        s2.pop();
        return a;
    }
    
    /** Get the front element. */
    int peek() {
        if(s2.empty()) {
            if(s1.empty())
                return -1;
            else {
                while(!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
                int a = s2.top();
             
                return a;
            }
        }
        int a = s2.top();
      
        return a;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(s1.empty() && s2.empty())
            return true;
        return false;
    }
};
