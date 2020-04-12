// Problem - 1408

// https://leetcode.com/problems/string-matching-in-an-array/

// O(n^2) time complexity and O(1) space complexity solution

class Solution {
public:
    vector <string> stringMatching(vector<string>& words) {
        vector <string> ans;
        for(string i : words) {
            for(string j : words) {
                if(i != j && j.find(i) != -1) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};
