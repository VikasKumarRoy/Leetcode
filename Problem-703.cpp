// Problem - 703

// https://leetcode.com/problems/kth-largest-element-in-a-stream/

// O(n) time complexity and O(n) space complexity solution

class KthLargest {
public:
    
    priority_queue <int, vector<int>, greater<int> > pq;
    
    KthLargest(int k, vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(i < k)
                pq.push(nums[i]);
            else {
                if(pq.top() <= nums[i]) {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if(pq.top() <= val) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */