// Problem - 1338

// https://leetcode.com/problems/reduce-array-size-to-the-half/

// O(nlogn) time complexity and O(n) space complexity solution

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int i = 0;
        int n = arr.size();
        unordered_map <int, int> um;
        for(int val : arr)
            um[val]++;
        vector <int> v;
        for(auto it : um)
            v.push_back(it.second);
        sort(v.begin(), v.end(), greater <int>());
        int sum = 0;
        for(i = 0; i < v.size(); i++) {
            sum += v[i];
            if(sum >= n/2)
                break;
        }
        return ++i;
    }
};