// Problem - 1614

// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, ctr = 0;
        for(char c : s) {
            if(c == '(')
                ctr++;
            else if(c == ')')
                ctr--;
            ans = max(ans, ctr);
        }
        return ans;
    }
};
