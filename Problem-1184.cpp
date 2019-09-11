//Problem - 1184
// https://leetcode.com/problems/distance-between-bus-stops/

// Time Complexity O(n) and O(1) space

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int dest) {
        if(start > dest)
            swap(start, dest);
        int total = accumulate(distance.begin(), distance.end(), 0);
        int sum1 = accumulate(distance.begin() + start, distance.begin() + dest, 0);
        return min(sum1, total - sum1);
    }
};