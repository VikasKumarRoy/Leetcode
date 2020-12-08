// Problem - 1010

// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map <int, int> um;
        int ans = 0;
        for(int i = 0; i < time.size(); i++) {
            int t = time[i]%60;
            if(t == 0) {
                if(um.count(0))
                    ans += um[0];
            }
            else {
                if(um.count(60-t))
                    ans += um[60-t];
            }
            um[t]++;
        }
        return ans;
    }
};
