//Problem  - 45
// https://leetcode.com/problems/jump-game-ii/

// O(n) greedy solution usign bfs the no. of jumps are equal to the no. of bfs levels

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 0 || nums[0] == 0)
            return false;
        
        int farthest = 0;
        int end = 0, jumps = 0;
        for(int i = 0; i < nums.size()-1; i++) {
            farthest = max(farthest, i + nums[i]);
            if(i == end) {
                jumps++;
                end = farthest;
            }
        }
        return jumps;
    }
};