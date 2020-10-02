// Problem - 1598

// https://leetcode.com/problems/crawler-log-folder/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(string s : logs) {
            if(s == "../")
                ans = max(0, ans-1);
            else if(s == "./")
                continue;
            else
                ans++;
        }
        return ans;
    }
};
