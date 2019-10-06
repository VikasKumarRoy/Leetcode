//Problem - 1217
// https://leetcode.com/problems/play-with-chips/

// Time Complexity O(n) and O(1) space

class Solution {
public:
    int minCostToMoveChips(vector <int>& v) {
        if(v.size() == 0)
            return 0;
        int odd = 0, even = 0;
        
        for(auto val : v) {
            if(val & 1)
                odd ++;
            else 
                even ++;
        }
        return min(odd, even);
    }
};


