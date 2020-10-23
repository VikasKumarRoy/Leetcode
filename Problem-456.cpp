// Problem - 456

// https://leetcode.com/problems/132-pattern/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        stack <int> s;
        int max2 = INT_MIN;
        for(int i = nums.size()-1; i >= 0; i--) {
            if(s.empty() || nums[i] > s.top()) {
                while(!s.empty() && nums[i] > s.top()) {
                    max2 = s.top();
                    s.pop();
                }
            }
            else {
                if(nums[i] < max2)
                    return true;
            }
            s.push(nums[i]);
        }
        return false;
    }
};

// OR O(n^2) quadratic approach with constant space

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        for(int i = 2; i < nums.size(); i++) {
            int mn, mx;
            mn = mx = -1;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    mn = j;
                    break;
                }
            }
            for(int j = i-1; j >= 0; j--) {
                if(nums[j] > nums[i]) {
                    mx = j;
                    break;
                }
            }
            if(mn != -1 && mx != -1 && mn < mx)
                return true;
        }
        return false;
    }
};
