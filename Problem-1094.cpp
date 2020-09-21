// Problem - 1094

// https://leetcode.com/problems/car-pooling/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector <int> road(1001, 0);
        for(auto v : trips) {
            road[v[1]] += v[0];
            road[v[2]] -= v[0];
        }
        int sum = 0;
        for(int i = 0; i < 1001; i++) {
            sum += road[i];
            if(sum > capacity)
                return false;
        }
        return true;
    }
};
