// Problem - 946

// https://leetcode.com/problems/validate-stack-sequences/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int j = 0;
        stack <int> s;
        for(int i = 0; i < n; i++) {
            s.push(pushed[i]);
            while(!s.empty() && j < n && s.top() == popped[j]) {
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};
