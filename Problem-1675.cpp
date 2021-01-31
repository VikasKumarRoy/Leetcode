// Problem - 1675

// https://leetcode.com/problems/minimize-deviation-in-array/

// O(nlogn) time complexity and O(n) space complexity solution

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;;
        priority_queue <int> maxHeap;
        priority_queue <int, vector <int>, greater <int>> minHeap;
        int mn = INT_MAX;
        for(int num : nums) {
            if(num&1)
                num *= 2;
            mn = min(mn, num);
            maxHeap.push(num);
        }
        while(!(maxHeap.top() & 1)) {
            int x = maxHeap.top();
            maxHeap.pop();
            ans = min(ans, x-mn);
            x /= 2;
            mn = min(mn, x);
            maxHeap.push(x);
        }
        return min(ans, maxHeap.top() - mn);
    }
};
