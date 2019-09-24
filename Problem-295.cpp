//Problem - 295
// https://leetcode.com/problems/find-median-from-data-stream/

// Time Complexity O(logn) and O(n) space complexity

class MedianFinder {
public:

    double median = 0;
    priority_queue <int> maxHeap;
    priority_queue <int, vector <int>, greater <int>> minHeap;
        
    void addNum(int num) {
        if(num <= median)
            maxHeap.push(num);
        else
            minHeap.push(num);
        if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if(minHeap.size() == maxHeap.size())
            median = (minHeap.top() + maxHeap.top()) / 2.0;
        else
            median = minHeap.size() > maxHeap.size() ? minHeap.top() : maxHeap.top();
    }
    
    double findMedian() {
        return median;
    }
};


