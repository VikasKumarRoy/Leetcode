// Problem - 1441

// https://leetcode.com/problems/build-an-array-with-stack-operations/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int i = 0, j = 1;
        vector <string> ans;
        while(i < target.size() && j <= n) {
            ans.push_back("Push");
            if(target[i] == j)
                i++;
            else
                ans.push_back("Pop");
            j++;
        } 
        return ans;
    }
};
