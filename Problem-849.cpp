// Problem - 849

// https://leetcode.com/problems/maximize-distance-to-closest-person/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ctr = 0, ans = 0;
        int last = -1;
        for(int i = 0; i < seats.size(); i++) {
            if(seats[i] == 1) {
                ans = max(ans, last == -1 ? i : (i-last)/2);
                last = i;
            }
        }
        return max(ans, (int)seats.size()-last-1);
    }
};
