//Problem - 42
// https://leetcode.com/problems/trapping-rain-water/

// O(n) time comlexity and O(n) space using dp

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n < 2)
            return 0;
        vector <int> left(n), right(n);
        left[0] = height[0];
        right[n-1] = height[n-1];
        for(int i = 1; i < n; i++)
            left[i] = max(left[i - 1], height[i]);
        for(int i = n-2; i >= 0; i--)
            right[i] = max(right[i + 1], height[i]);
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans += min(left[i], right[i]) - height[i];
        return ans;
    }
};

// using stack

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n < 2)
            return 0;
        int ans = 0; 
        stack <int> s;
        int i = 0;
        while(i < n) {
            if(s.empty() || height[s.top()] >= height[i])
                s.push(i++);
            else {
                int t = s.top();
                s.pop();
                if(s.empty())
                    continue;
                int dist = i - s.top() - 1;
                ans += (min(height[i], height[s.top()]) - height[t]) * dist;
            }
        }
        return ans;
    }
};
   
// O(n) time and O(1) space solution

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2)
            return 0;
        int ans = 0;
        int maxL, maxR, i, j;
        i = maxL = 0;
        j = maxR = n-1;
        while(i < j) {
            if(height[maxL] < height[maxR]) {
                i++;
                if(height[maxL] < height[i])
                    maxL = i;
                ans += height[maxL] - height[i];
            } else {
                j--;
                if(height[maxR] < height[j])
                    maxR = j;
                ans += height[maxR] - height[j];
            }
        }
        return ans;
    }
};   