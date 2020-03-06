// Problem - 703

// https://leetcode.com/problems/kth-largest-element-in-a-stream/

// O(nlogk) time complexity and O(k) space complexity solution

class KthLargest {
public:
    
    priority_queue <int, vector<int>, greater<int> > pq;
    int K;
    
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int val : nums)
            add(val);
    }
    
    int add(int val) {
        if(pq.size() < K)
            pq.push(val);
        else if(pq.top() <= val) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

