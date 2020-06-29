// Problem - 1496

// https://leetcode.com/problems/path-crossing/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set < pair<int, int>, bool, hash_pair > us;
        pair <int, int> p = {0, 0};
        us.insert(p);
        for(char c : path) {
            switch(c) {
                case 'N':
                    p.first++;
                    break;
                case 'S':
                    p.first--;
                    break;
                case 'W':
                    p.second--;
                    break;
                case 'E':
                    p.second++;
                    break;
            }
            if(us.count(p))
                return true;
            us.insert(p);
        }
        return false;
    }
};
