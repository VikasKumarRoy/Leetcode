// Problem - 528

// https://leetcode.com/problems/random-pick-with-weight/

// O(logn) time complexity and O(n) space complexity solution using binary search

class Solution {
public:
    vector <int> pref; 
    
    Solution(vector<int>& w) {
        for(int val: w) {
            if(pref.empty())
                pref.push_back(val);
            else
                pref.push_back(val + pref.back());
        }
    }
    
    int pickIndex() {
        int r = rand() % pref.back();
        auto it = lower_bound(pref.begin(), pref.end(), r + 1);
        return it - pref.begin();
    }
};
