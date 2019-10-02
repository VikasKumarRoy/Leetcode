//Problem - 292
// https://leetcode.com/problems/nim-game/

// Time Complexity O(1) in constant space

class Solution {
public:
    bool canWinNim(int n) {
        if(n%4 == 0)
            return false;
        return true;
    }
};

