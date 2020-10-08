// Problem - 84

// https://leetcode.com/problems/largest-rectangle-in-histogram/

// O(n) time complexity and O(n) space complexity solution using stack

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> s;
        int i = 0, n = heights.size();
        int maxArea = 0;
        while(i < n) {
            if(s.empty() || heights[s.top()] < heights[i])
                s.push(i++);
            else {
                int h = s.top();
                s.pop();
                int area = heights[h] * (i - 1 - (s.empty() ? -1 : s.top()));
                maxArea = max(area, maxArea);
            }
        }
        while(!s.empty()) {
            int h = s.top();
            s.pop();
            int area = heights[h] * (i - 1 - (s.empty() ? -1 : s.top()));
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};
