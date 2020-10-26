// Problem - 1629

// https://leetcode.com/problems/slowest-key/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int mx = releaseTimes[0];
        char ans = keysPressed[0];
        for(int i = 1; i < releaseTimes.size(); i++) {
            int time = releaseTimes[i] - releaseTimes[i-1];
            if(time > mx) {
                mx = time;
                ans = keysPressed[i];
            }
            else if(time == mx && ans < keysPressed[i])
                ans = keysPressed[i];
        }
        return ans;
    }
};
