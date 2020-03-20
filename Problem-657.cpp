// Problem - 657

// https://leetcode.com/problems/robot-return-to-origin/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map <char, int> um;
        for(char c : moves)
            um[c]++;
        return um['U'] == um['D'] && um['L'] == um['R'];
    }
};
