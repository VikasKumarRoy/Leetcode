//Problem - 1051

// https://leetcode.com/problems/height-checker/

// O(nlogn) time complexity and O(n) space complexity sol

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ans = 0;
        vector <int> temp(heights.begin(), heights.end());
        sort(temp.begin(), temp.end());
        for(int i = 0; i < heights.size(); i++)
            if(temp[i] != heights[i])
                ans++;
        return ans;
    }
};