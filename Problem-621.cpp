 
// Problem - 621

// https://leetcode.com/problems/task-scheduler/

// O(n) time complexity and O(1) space complexity solution using greedy approach

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector <int> freq(26, 0);
        int mx = 0;
        int ctr = 0;
        for(char c : tasks) {
            freq[c - 'A']++;
            if(freq[c - 'A'] > mx) {
                mx = freq[c - 'A'];
                ctr = 1;
            }
            else if(freq[c - 'A'] == mx)
                ctr++;
        }
        int rest = tasks.size() - (mx * ctr);
        int idle = (mx - 1) * (n - (ctr - 1));
        idle = max(0, idle - rest);
        return tasks.size() + idle;
    }
};
