// Problem - 735

// https://leetcode.com/problems/asteroid-collision/

// O(n) time complexity and O(n) space complexity solution using stack

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> s;
        for(auto rock : asteroids) {
            if(rock < 0) {
                while(!s.empty() && s.top() > 0 && abs(rock) > s.top()) {
                    s.pop();
                }
                if(!s.empty() && s.top() == -1*(rock))
                    s.pop();
                else if(s.empty() || s.top() < 0)
                    s.push(rock);
            }
            else {
                s.push(rock);
            }
        }
        vector <int> ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
