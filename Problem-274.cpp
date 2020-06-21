// Problem - 274

// https://leetcode.com/problems/h-index/

// O(n) time complexity and O(n) space complexity solution using counting sort

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n == 0)
            return 0;
        vector <int> v(n+1, 0);
        for(int i = 0; i < n; i++) {
            if(citations[i] < n) {
                v[citations[i]]++;
            }
        }
        int sum = 0, ans = 0;
        for(int i = 0; i <= n; i++) {
            if(n - sum >= i)
                ans = max(i, ans);
            sum += v[i];
        }
        return ans;
    }
};
