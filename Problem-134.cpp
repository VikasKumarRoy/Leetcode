// Problem - 134

// https://leetcode.com/problems/gas-station/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tank = 0, gas_needed = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            tank += gas[i] - cost[i];
            if(tank < 0) {
                gas_needed += tank;
                tank = 0;
                ans = (i+1)%n;
            }
        }
        if(tank >= abs(gas_needed))
            return ans;
        return -1;
    }
};
