// Problem - 1291

// https://leetcode.com/problems/sequential-digits/

// O(1) time complexity and O(n) space complexity solution

class Solution {
public:
    
    vector<int> sequentialDigits(int low, int high) {
        vector <int> ans;
        string s1 = to_string(low), s2 = to_string(high);
        int n = s1.size(), m = s2.size();
        for(int i = n; i <= m; i++) {
            for(int j = 1; j < 9; j++) {
                string d;
                d += to_string(j);
                while(d.size() < i && j + d.size() < 10) {
                    d += to_string(j + d.size());
                }
                int num = stoi(d);
                if(num >= low && num <= high && d.size() == i)
                    ans.push_back(num);
                if(num > high)
                    break;
            }
        }
        return ans;
    }
};
