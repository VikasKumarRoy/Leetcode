// Problem - 1299

// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector <int> ans(n, 0);
        ans[n-1] = -1;
        for(int i = n-2; i >= 0; i--)
            ans[i] = max(ans[i+1], arr[i+1]);
        return ans;
    }
};