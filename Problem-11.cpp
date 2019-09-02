//Problem - 11
// https://leetcode.com/problems/container-with-most-water/

// O(n) time comlexity and O(1) space solution passes all tc

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int max_area = 0;
        while(i < j) {
            int area = min(height[i], height[j]) * (j - i);
            max_area = max(max_area, area);
            height[i] < height[j] ? i++ : j--;
        }
        return max_area;
    }
};
   