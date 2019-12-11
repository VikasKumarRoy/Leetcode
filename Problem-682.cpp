//Problem - 682

// https://leetcode.com/problems/baseball-game/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    
    int calPoints(vector<string>& ops) {
        int ans = 0;
        stack <int> s;
        for(int i = 0; i < ops.size(); i++) {
            if(ops[i] == "C") {
                ans -= s.top();
                s.pop();
            }
            else if(ops[i] == "D") {
                ans += s.top() * 2;
                s.push(s.top()*2);
            }
            else if(ops[i] == "+") {
                int t = s.top();
                s.pop();
                int val = s.top() + t;
                ans += val;
                s.push(t);
                s.push(val);
            }
            else {
                ans += stoi(ops[i]);
                s.push(stoi(ops[i]));
            }
        }
        return ans;
    }
};