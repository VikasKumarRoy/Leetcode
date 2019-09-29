//Problem - 1207
// https://leetcode.com/problems/unique-number-of-occurrences/

// Time Complexity O(n) and O(n) space complexity

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map <int, int> freq;
        unordered_set <int> visited;
        for(auto v : arr)
            freq[v]++;
        for(auto v : freq) {
            if(visited.find(v.second) != visited.end())
                return false;
            else
                visited.insert(v.second);
        }
        return true;
    }
};


