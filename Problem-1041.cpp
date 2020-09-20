// Problem - 1041

// https://leetcode.com/problems/robot-bounded-in-circle/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int i = 0;
        string dir = "NESW";
        vector <int> pos(4, 0);
        for(char c : instructions) {
            if(c == 'R') {
                i = (i+1)%4;
            }
            else if(c == 'L') {
                i--;
                if(i == -1)
                    i = 3;
            }
            else {
                pos[i]++;
            }
        }
        if(abs(pos[2]-pos[0]) == 0 && abs(pos[3]-pos[1]) == 0)
            return true;
        return i != 0;
    }
};
