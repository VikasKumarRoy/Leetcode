// Problem - 1736

// https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/

// O(1) time complexity and O(1) space complexity solution

class Solution {
public:
    string maximumTime(string time) {
        string maxTime = "23059";
        string s;
        for(int i = 0; i <= 5; i++) {
            if(time[i] == '?') {
                if(i == 1 && time[i-1] != '2')
                    time[i] = '9';
                else if(i == 0 && time[i+1] >= '4' && time[i+1] != '?')
                    time[i] = '1';
                else {
                    time[i] = maxTime[i];
                }
            }
        }
        return time;
    }
};
